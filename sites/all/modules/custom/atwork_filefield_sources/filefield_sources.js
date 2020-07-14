(function ($) {

/**
 * Behavior to add source options to configured fields.
 */
Drupal.behaviors.fileFieldSources = {};
Drupal.behaviors.fileFieldSources.attach = function(context, settings) {
  $("div.filefield-sources-list:not(.filefield-sources-processed)", context).each(function() {
    $(this).addClass("filefield-sources-processed");
    let $fileFieldElement = $(this).parents("div.form-managed-file:first");
    $(this).find("a").click(function() {
      // Remove the active class.
      $(this).parents("div.filefield-sources-list").find("a.active").removeClass("active");

      // Find the unique FileField Source class name.
      const fileFieldSourceClass = this.className.match(/filefield-source-[0-9a-z]+/i)[0];

      // The default upload element is a special case.
      if ($(this).is(".filefield-source-upload")) {
        $fileFieldElement.find("div.filefield-sources-list").siblings(".form-file, .form-submit").css("display", "");
        $fileFieldElement.find("div.filefield-source").css("display", "none");
      }
      else {
        $fileFieldElement.find("div.filefield-sources-list").siblings(".form-file, .form-submit").css("display", "none");
        $fileFieldElement.find("div.filefield-source").not("div." + fileFieldSourceClass).css("display", "none");
        $fileFieldElement.find("div." + fileFieldSourceClass).css("display", "");
      }

      // Add the active class.
      $(this).addClass("active");
      Drupal.fileFieldSources.updateHintText($fileFieldElement.get(0));
    }).first().triggerHandler("click");

    // Clipboard support.
    $fileFieldElement.find(".filefield-source-clipboard-capture")
      .bind("paste", Drupal.fileFieldSources.pasteEvent)
      .bind("focus", Drupal.fileFieldSources.pasteFocus)
      .bind("blur", Drupal.fileFieldSources.pasteBlur);
  });

  if (context === document) {
    $("form").submit(function() {
      Drupal.fileFieldSources.removeHintText();
    });
  }
};

/**
 * Helper functions used by FileField Sources.
 */
Drupal.fileFieldSources = {
  /**
   * Update the hint text when clicking between source types.
   */
  updateHintText: function(fileFieldElement) {
    // Add default value hint text to text fields.
    $(fileFieldElement).find('div.filefield-source').each(function() {
      const matches = this.className.match(/filefield-source-([a-z]+)/);
      const sourceType = matches[1];
      const textfield = $(this).find('input.form-text:first').get(0);
      const defaultText = (Drupal.settings.fileFieldSources && Drupal.settings.fileFieldSources[sourceType]) ? Drupal.settings.fileFieldSources[sourceType].hintText : '';

      // If the field doesn't exist, just return.
      if (!textfield) {
        return;
      }

      // If this field is not shown, remove its value and be done.
      if (!$(this).is(':visible') && textfield.value == defaultText) {
        textfield.value = '';
        return;
      }

      // Set a default value:
      if (textfield.value == '') {
        textfield.value = defaultText;
      }

      // Set a default class.
      if (textfield.value == defaultText) {
        $(textfield).addClass('hint');
      }

      $(textfield).focus(hideHintText);
      $(textfield).blur(showHintText);

      function showHintText() {
        if (this.value == '') {
          this.value = defaultText;
          $(this).addClass('hint');
        }
      }

      function hideHintText() {
        if (this.value == defaultText) {
          this.value = '';
          $(this).removeClass('hint');
        }
      }
    });
  },

  /**
   * Delete all hint text from a form before submit.
   */
  removeHintText: function() {
    $('div.filefield-source input.hint').val('').removeClass('hint');
  },

  /**
   * Clean up the default value on focus.
   */
  pasteFocus: function(e) {
    // Set default text.
    if (!this.defaultText) {
      this.defaultText = this.innerHTML;
      this.innerHTML = '';
    }
    // Remove non-text nodes.
    $(this).children().remove();
  },

  /**
   * Restore default value on blur.
   */
  pasteBlur: function(e) {
    if (this.defaultText && !this.innerHTML) {
      this.innerHTML = this.defaultText;
    }
  },

  pasteEvent: function(e) {
    let clipboardData = null;
    let targetElement = this;

    // Chrome.
    if (window.event && window.event.clipboardData && window.event.clipboardData.items) {
      clipboardData = window.event.clipboardData;
    }
    // All browsers in the future (hopefully).
    else if (e.originalEvent && e.originalEvent.clipboardData && e.originalEvent.clipboardData.items) {
      clipboardData = e.originalEvent.clipboardData;
    }
    // Firefox with content editable pastes as img tag with data href.
    else if ($.browser.mozilla) {
      Drupal.fileFieldSources.waitForPaste(targetElement);
      return true;
    }
    else {
      Drupal.fileFieldSources.pasteError(targetElement, Drupal.t('Paste from clipboard not supported in this browser.'));
      return false;
    }

    const items = clipboardData.items;
    const types = clipboardData.types;
    const filename = targetElement.firstChild ? targetElement.firstChild.textContent : '';

    // Handle files and image content directly in the clipboard.
    let fileFound = false;
    let fileBlob;
    let fileReader;
    let n;
    for (n = 0; n < items.length; n += 1) {
      if (items[n] && items[n].kind === 'file') {
        fileBlob = items[n].getAsFile();
        fileReader = new FileReader();
        // Define events to fire after the file is read into memory.
        fileReader.onload = function () {
          Drupal.fileFieldSources.pasteSubmit(targetElement, filename, this.result);
        };
        fileReader.onerror = function () {
          Drupal.fileFieldSources.pasteError(targetElement, Drupal.t('Error reading file from clipboard.'));
        };
        // Read in the file to fire the above events.
        fileReader.readAsDataURL(fileBlob);
        fileFound = true;
        break;
      }
    }
    if (!fileFound) {
      Drupal.fileFieldSources.pasteError(targetElement, Drupal.t('No file in clipboard.'));
    }
    return false;
  },

  /**
   * For browsers that don't support native clipboardData attributes.
   */
  waitForPaste: function(targetElement) {
    if (targetElement.children && targetElement.children.length > 0) {
      const filename = targetElement.firstChild ? targetElement.firstChild.textContent : '';
      let tagFound = false;
      $(targetElement).find('img[src^="data:image"]').each(function(n, element) {
        Drupal.fileFieldSources.pasteSubmit(targetElement, filename, element.src);
        tagFound = true;
      });
      $(targetElement).html(filename);
      if (!tagFound) {
        Drupal.fileFieldSources.pasteError(targetElement, Drupal.t('No file in clipboard.'));
      }
    }
    else {
      setTimeout(function() {
        Drupal.fileFieldSources.waitForPaste(targetElement);
      }, 200);
    }
  },

  /**
   * Set an error on the paste field temporarily then clear it.
   */
  pasteError: function(domElement, errorMessage) {
    const $description = $(domElement).parents('.filefield-source-clipboard:first').find('.description');
    if (!$description.data('originalDescription')) {
      $description.data('originalDescription', $description.html())
    }
    $description.html(errorMessage);
    const errorTimeout = setTimeout(function() {
      $description.html($description.data('originalDescription'));
      $(this).unbind('click.pasteError');
    }, 3000);
    $(domElement).bind('click.pasteError', function() {
      clearTimeout(errorTimeout);
      $description.html($description.data('originalDescription'));
      $(this).unbind('click.pasteError');
    });
  },

  /**
   * After retreiving a clipboard, post the results to the server.
   */
  pasteSubmit: function(targetElement, filename, contents) {
    const $wrapper = $(targetElement).parents('.filefield-source-clipboard');
    $wrapper.find('.filefield-source-clipboard-filename').val(filename);
    $wrapper.find('.filefield-source-clipboard-contents').val(contents);
    $wrapper.find('input.form-submit').trigger('mousedown');
  }
};

})(jQuery);
