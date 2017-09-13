(function ($) {

    $(document).ready(function(){

        // Handle clicking on search button here.
        $("#custom-search-blocks-form-1 #search-button").click(function(){
            // Process search request
            $("#custom-search-blocks-form-1").submit();

            setLoadingAnimation();            
        });

        // Handle when users presses 'enter' to search
        $('#edit-custom-search-blocks-form-1--2').keypress(function(event) {
            if (event.which == 13) {
                 $("#custom-search-blocks-form-1").submit();
                 setLoadingAnimation();
            }
            
        });

        var setLoadingAnimation = function () {
            if($('#edit-custom-search-blocks-form-1--2').val()) {
                if(checkIE() && checkIE() < 10) {
                    //Set Loading animation for IE9.0 or lower
                    $("#custom-search-blocks-form-1 #search-button").replaceWith('<div class="search-busy"></div>');
                } else {
                    // All other browsers
                    $("#custom-search-blocks-form-1 #search-button").replaceWith('<div class="spinner"><div class="rect1"></div><div class="rect2"></div><div class="rect3"></div><div class="rect4"></div><div class="rect5"></div><div class="rect6"></div></div>');
                }
            }
        }

        var checkIE = function () {
            // Return false if not IE, else return IE version number
            var myNav = navigator.userAgent.toLowerCase();
            return (myNav.indexOf('msie') != -1) ? parseInt(myNav.split('msie')[1]) : false;
        }

    });

})(jQuery);
