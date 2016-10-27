(function ($) {
  Drupal.behaviors.atwork_rate = {
    attach: function(context) {
      $('.atwork-rate-widget:not(.atwork-rate-processed)', context).addClass('atwork-rate-processed').each(function () {
        var widget = $(this);
        var ids = widget.attr('id').match(/^atwork_rate\-([a-z]+)\-([0-9]+)\-([0-9]+)\-([0-9])$/);
        var data = {
          entity_type: widget.attr('data-entity-type'),
          entity_id: widget.attr('data-entity-id'),
          field_name: widget.attr('data-field'),
          widget_mode: widget.attr('data-mode')
        };

        $('a.atwork-rate-button', widget).click(function() {
          var token = $(this).attr('data-token');
          return Drupal.atworkRateVote(widget, data, token);
        });

        // Save description in attribute so we can reset this on mouseout.
        widget.attr('data-description', $('span.atwork-rate-description', widget).text());

        var s = widget.attr('data-highlight-mouseover');
        var d = widget.attr('data-desc-mouseover');
        var index = 0;
        $('a.atwork-rate-button', widget).each(function() {
          // Number all buttons for the before / after highlighting.
          $(this).attr('data-index', index);

          // Store the initial highlighted state so we can reset this on mouseout.
          $(this).attr('data-highlighted', $(this).hasClass('highlighted') ? 1 : 0);

          $(this).hover(function() {
            if (s) {
              // Highlighting on mouseover is enabled.
              $('a.atwork-rate-button', $(this).parent()).removeClass('highlighted');
            }
            if (s & 1) {
              // Highlight current button.
              $(this).addClass('highlighted');
            }
            if (s & 2) {
              // Highlight buttons before current button.
              $('a.atwork-rate-button:lt(' + $(this).attr('data-index') + ')', $(this).parent()).addClass('highlighted');
            }
            if (s & 4) {
              // Highlight buttons after current button.
              $('a.atwork-rate-button:gt(' + $(this).attr('data-index') + ')', $(this).parent()).addClass('highlighted');
            }
            if (d.length) {
              var desc = d.replace('@vote', $(this).text());
              $('span.atwork-rate-description', widget).text(desc);
            }
          });

          $(this).mouseout(function() {
            $('a.atwork-rate-button', $(this).parent()).each(function() {
              if ($(this).attr('data-highlighted') == 1) {
                $(this).addClass('highlighted');
              }
              else {
                $(this).removeClass('highlighted');
              }
              $('span.atwork-rate-description', widget).text(widget.attr('data-description'));
            });
          });

          ++index;
        });
      });
    }
  };

  Drupal.atworkRateVote = function(widget, data, token) {
    // Invoke JavaScript hook.
    widget.trigger('eventBeforeAtworkRate', [data]);

    $(".atwork-rate-description", widget).text(Drupal.t('Saving vote...'));

    // Random number to prevent caching, see http://drupal.org/node/1042216#comment-4046618
    var random = Math.floor(Math.random() * 99999);

    var q = Drupal.settings.atwork_rate.basePath.match(/\?/) ? '&' : '?' + 'field_name=' + data.field_name + '&entity_type=' + data.entity_type + '&entity_id=' + data.entity_id + '&widget_mode=' + data.widget_mode + '&rate=' + token + '&destination=' + encodeURIComponent(Drupal.settings.rate.destination) + '&r=' + random;
    if (data.value) {
      q = q + '&value=' + data.value;
    }

    $.get(Drupal.settings.atwork_rate.basePath + q, function(response) {
      if (response.match(/^https?\:\/\/[^\/]+\/(.*)$/)) {
        // We got a redirect.
        document.location = response;
      }
      else {
        // Get parent object.
        var p = widget.parent();

        // Invoke JavaScript hook.
        widget.trigger('eventAfterAtworkRate', [data]);

        widget.before(response);

        // Remove widget.
        widget.remove();
        widget = undefined;

        Drupal.attachBehaviors(p.get(0));
      }
    });

    return false;
  }
})(jQuery);
