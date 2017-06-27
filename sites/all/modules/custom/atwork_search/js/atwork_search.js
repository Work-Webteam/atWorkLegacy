(function ($) {

    $(document).ready(function(){

        // Handle clicking on search button here.
        $("#custom-search-blocks-form-1 #search-button").click(function(){
            // Process search request
            //$("#custom-search-blocks-form-1").submit();

            setLoadingAnimation();            
        });

        // Handle when users presses 'enter' to search
        $('#edit-custom-search-blocks-form-1--2').keypress(function(event) {
            if (event.which == 13) setLoadingAnimation();
        });

        var setLoadingAnimation = function () {
            //console.log('1');
            if($('#edit-custom-search-blocks-form-1--2').val()) {
                $("#custom-search-blocks-form-1 #search-button").replaceWith('<div class="spinner"><div class="rect1"></div><div class="rect2"></div><div class="rect3"></div><div class="rect4"></div><div class="rect5"></div><div class="rect6"></div></div>');
            }
        }

    });

})(jQuery);
