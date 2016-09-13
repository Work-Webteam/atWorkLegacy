

(function($) { $(document).ready(function() {

      function write_block_order() {
        var output = [];
        var counter = 0;

        $(".node-section-form .sortable li").each( function( index, element ){
          output.push([$(this).text()]);
          counter = counter + 1;
        });

        $('.field-name-field-grp-opt-block-order textarea').html(output.join('|'));
      }

      function modify_block(block, action) {
        var exists = false;

        $(".node-section-form .sortable li").each( function( index, element ){
          if ($(this).text() == block) {
            if (action == 'add') {
              exists = true;
            }
            else {
              $(this).remove();
            }
          }
        });

        if (action == 'add' && exists === false) {
          $('ol.sortable').append('<li>' + block + '</li>');
        }
      }

      function reset_block_order() {
        if ($('#edit-field-grp-opt-blog-sidebar-und').prop('checked') === true) {
          modify_block('Blogs', 'add');
        }
        else {
          modify_block('Blogs', 'delete');
        }

        if ($('#edit-field-grp-opt-event-sidebar-und').prop('checked') === true) {
          modify_block('Events', 'add');
        }
        else {
          modify_block('Events', 'delete');
        }

        if ($('#edit-field-grp-opt-poll-sidebar-und').prop('checked') === true) {
          modify_block('Polls', 'add');
        }
        else {
          modify_block('Polls', 'delete');
        }

        if ($('#edit-field-grp-opt-gallery-sidebar-und').prop('checked') === true) {
          modify_block('Galleries', 'add');
        }
        else {
          modify_block('Galleries', 'delete');
        }

        if ($('#edit-field-grp-opt-issue-sidebar-und').prop('checked') === true) {
          modify_block('Task List', 'add');
        }
        else {
          modify_block('Task List', 'delete');
        }

        if ($('#edit-field-grp-opt-qa-sidebar-und').prop('checked') === true) {
          modify_block('Question And Answers', 'add');
        }
        else {
          modify_block('Question And Answers', 'delete');
        }
      }

      //on page load
      reset_block_order();
      write_block_order();

      $('fieldset.group-advanced input').change(function() {
        reset_block_order();
        $('#edit-field-group-type-und-0').prop('checked', true);
      });

      $("input[name='field_group_type[und]']").click(function() {
        //alert($(this).val());

        if ($(this).val() > 0) {
          $('fieldset.group-advanced input').prop('checked', false).change();
        }

        // social group
        if ($(this).val() == 1) {
          $('#edit-field-grp-opt-blog-und').prop('checked', true).change();
          $('#edit-field-grp-opt-blog-sidebar-und').prop('checked', true).change();
          $('#edit-field-grp-opt-event-und').prop('checked', true).change();
          $('#edit-field-grp-opt-event-sidebar-und').prop('checked', true).change();
          $('#edit-field-grp-opt-event-sidebar-cal-und-1').prop('checked', true).change();
          $('#edit-field-grp-opt-poll-und').prop('checked', true).change();
          $('#edit-field-grp-opt-poll-sidebar-und').prop('checked', true).change();
          $('#edit-field-grp-opt-gallery-und').prop('checked', true).change();

          $('#edit-field-group-type-und-1').prop('checked', true);
        }

        // reference group
        if ($(this).val() == 2) {
          $('#edit-field-grp-opt-page-und').prop('checked', true).change();
          //$('#edit-og-menu').prop('checked', true).change();
          $('#edit-field-group-content-home-und').prop('checked', false).change();

          $('#edit-field-group-type-und-2').prop('checked', true);
        }

        // project
        if ($(this).val() == 3) {
          $('#edit-field-grp-opt-qa-und').prop('checked', true).change();
          $('#edit-field-grp-opt-qa-sidebar-und').prop('checked', true).change();
          $('#edit-field-grp-opt-issue-und').prop('checked', true).change();
          $('#edit-field-grp-opt-issue-sidebar-und').prop('checked', true).change();
          $('#edit-field-grp-opt-file-und').prop('checked', true).change();

          $('#edit-field-group-type-und-3').prop('checked', true);
        }

        // custom group
        if ($(this).val() == 0) {
          // click open the advanced setting fieldset
          Drupal.toggleFieldset(jQuery('#node_section_form_group_advanced'));
        }

      });

      // change name of stupid next/previous buttons
      //$('.multipage-link-next').val('Custom Options \u00bb');
      //$('.multipage-link-previous').val('\u00ab Basic Options');


      $( ".sortable" ).sortable({
        stop: function( event, ui ) {
          write_block_order();
        }
      });
      $( ".sortable" ).disableSelection();
});})(jQuery);
