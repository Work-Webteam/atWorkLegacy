var selectItems = {
    // In BC Public Service Since
    1: "[Please enter the year in which you started with the BC Public Service]",
    // Previous Position Held
    2: "[Please enter any previous position(s) or other work experience you want to share as part of your profile]",
    // Career Highlight
    3: "[Please describe your career highlight(s) to date. This could be your favourite project, team, work location, etc.]",
    // First Job in the BC Public Service
    4: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    // Career History in the BC Public Service
    5: "[Please describe your career path leading up to your current position - how did you get to where you are today?]",
    // Other Career History
    6: "[Please share any other information regarding your career that others might be interested in. What was the best job you had? What was the craziest job you had? Which boss did you learn the most from?]",
    // Most Recent Education/Training
    7: "[Please share any recent education or training in which you have participated. You may also choose to share how you found the learning relevant to your work]",
    // Education Background
    8: "[Please share any formal education or training which helped you get to your current position]",
    
    // What do you value about working in the BC Public Service? 
    101: "[Please enter any previous position(s) or other work experience you want to share as part of your profile]",
    // Mentors
    102: "[Please describe your career highlight(s) to date. This could be your favourite project, team, work location, etc.]",
    // Favourite Quotes
    103: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    
    // Hometown
    201: "[Please enter any previous position(s) or other work experience you want to share as part of your profile]",
    // Memorable Vacation
    202: "[Please describe your career highlight(s) to date. This could be your favourite project, team, work location, etc.]",
    // Other Places I've Been
    203: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    // Hobbies/Interests
    204: "[Please enter the year in which you started with the BC Public Service]",
    // Best Health and Wellness Tip
    205: "[Please enter any previous position(s) or other work experience you want to share as part of your profile]",
    // Family/Pets
    206: "[Please describe your career highlight(s) to date. This could be your favourite project, team, work location, etc.]",
    // Childhood Ambition
    207: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    // Favourite Movie
    208: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    // Favourite Food
    209: "[Please enter any previous position(s) or other work experience you want to share as part of your profile]",
    // Favourite Sports Team
    210: "[Please describe your career highlight(s) to date. This could be your favourite project, team, work location, etc.]",
    // Favourite Song
    211: "[Please describe your first job in government, and how things may (or may not) have changed since then]",
    // Astrological Sign
    212: "[Please describe your first job in government, and how things may (or may not) have changed since then]"
    
  }

function atworkProfilesIsDefault(text) {
  if (text.length == 0) {
    return true;
  }
  
  for (var key in selectItems) {
    if (selectItems[key] == text) {
      return true;
    }
  }

  return false;
}



(function ($) {

/**
 * Auto-hide summary textarea if empty and show hide and unhide links.
 */
Drupal.behaviors.atworkProfiles = {
  attach: function (context, settings) {
    // clear empty table rows
    $('.field-type-field-collection td:empty', context).each(function() {
      var tr = $(this).closest('tr');
      tr.hide();
    });
    
    $('#user-profile-form .field-name-field-answer textarea').click(function(){
      if (atworkProfilesIsDefault($(this).val())) {
        $(this).val('');
      }
    });

    $('#user-profile-form .field-name-field-question select').change(function() {
      var id = $(this).val();
      if (id == 'select_or_other') {
        return;
      }
      var textField = $(this).closest('td').find('textarea');
      if (atworkProfilesIsDefault(textField.val()) && selectItems[id].length > 0) {
        textField.val(selectItems[id]);
      }
    });
  }
};

})(jQuery);