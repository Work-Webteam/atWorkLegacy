/**
 * JS function for LSA Gift choices
 * Library from: http://trentrichardson.com/Impromptu/
 * Drupal.jquery
 * Written by Thayne Werdal Feb 2016
 */

(function ($) {
/**
 * Function for those who choose 25 years of service
 * Includes impromptu library
 * Updates form fields for /career/long-service-awards/form
 */

  function _25year() {
    // Using the impromptu library for this: http://trentrichardson.com/Impromptu/
    var gift_chooser = {
      state0: {
        title: 'Congratulations on 25 years!',
        // All HTML in one long string - pretty much any html tags can go here, and will be replicated in the popup.
        html: '<p>Please use the drop-down menu to view and choose your award from the list below. Once you have chosen your award, click on "Accept" to return to the LSA form.<p>'+
        /**
         * Select List
         */
        '<label>Award Options: <select name="_25_year_option" id="gift_selection_box"><br />' +
          // Blue ballpoint pen
          '<option value="Cross Starry Blue ballpoint pen" name="blue_xp_ball_point_pen" id="25_gift_blue_pen">Cross "Starry Blue" ballpoint pen</option>' +
          // Silver lapel pin
          '<option value="Cross Tablet holder" name="cross_tablet_holder" id="25_cross_tablet_holder">Cross Tablet holder with note pad</option>' +
          // Pearl Earrings
          '<option value="Sterling Silver and White Pearl Earrings" name="pearl_earrings" id="25_gift_pearl_earrings">Pearl Earrings</option>' +
          // Padfolio/ipad holder
          '<option value="Passport and Luggage tag set" name="passport_luggage_tag" id="25_gift_passport_luggage_tag">Passport and Luggage tag set</option>' +
          // PECSF donation
          '<option value= "PECSF Fund" name="provincial_employees_community_services_fund" id="25_pecsf">Charitable Donation</option>' +
        '</select></label>' +


        /**
         * 25 Year Gift Certificate Name Text
         * We want users to see this - and we want it to be "Required"
         */


        /**
         * Image List
         * NOTE: image id must match option "name" variable preceeded by image_ for the image to show.
         */
        '<div id="lsa_gift_images_div">' +
          // Blue ball point pen
          '<img src="/sites/default/files/lsa_2015/25_ballpoint-pen-final.jpg" alt="Blue ballpoint pen" id="image_blue_xp_ball_point_pen"><br />'+
          //silver lapel pin
          '<img src="/sites/default/files/lsa_2015/25_padfolio_with_embossed_image_2017.jpg" alt="Cross Tablet holder" id="image_cross_tablet_holder"><br />' +
          // Pearl Earrings
          '<img src="/sites/default/files/lsa_2015/25_pearle_earrings.jpg" alt="Sterling Silver Pearl earrings" id="image_pearl_earrings"><br />' +
          //Padfolio
          '<img src="/sites/default/files/lsa_2015/25_passport_luggage_tag_set.png" alt="Passport and Luggage tag picture" id="image_passport_luggage_tag"><br />' +
          // PECSF donation
          '<img src="/sites/default/files/lsa_2015/25_pecsf.jpg" alt="PECSF donation image" id="image_provincial_employees_community_services_fund"><br />' +
        '</div>' +
        /**
         * More info list
         * NOTE: related span id must match option "name" variable preceeded by info_ for the image to show.
         */
        '<div id = "lsa_more_info_div">' +
          // Blue ball point pen
          '<span id="info_blue_xp_ball_point_pen"><p>A refined profile combined with a stunningly deep starry blue resin finish for timeless appeal.</p><br /><p>Colour: blue</p><p>Size: 5.54" H</p><p> Imprinted on pen: 25 Years </p></span>' +
          // Silver lapel pin
          '<span id= "info_cross_tablet_holder"><p>Genuine leather cover features a cleverly integrated pen sleeve. Zippered closure keeps your tablet secure during transport. Adjustable brackets hold most tablet models including all versions of the iPad including the iPad Air.</p><br /><p>Colour: black </p><p>Size: 10.5" H X 1" W X 9" L  </p><p>Debossed on front: 25 years </p></span>' +
          // Pearl Earrings
          '<span id="info_pearl_earrings"><p>Sterling sliver and fresh water pearl earrings with accent of gold.</p><p>Made in Vancouver  BC, by Howling Dog Artisan Jewellery.</p><br /><p><a href="http://www.howlingdogart.com/" target="_blank">Website</a></p></span>' +
          // Padfolio
          '<span id= "info_passport_luggage_tag"><p>This Passport / magnetic luggage tag set is a fantastic gift for the frequent flyers.</p><br /><p>Full grain leather  passport cover and a unique magnetic luggage tag.</p><br /><p>Colour: black</p><p>Debossed on front: 25 years</p></span>' +
          // PECSF donation
          '<span id="info_provincial_employees_community_services_fund"><p>In lieu of receiving a Long Service Award, you may opt to make a charitable donation via <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf" target="_blank">PECSF</a>. You may choose to donate to any registered charitable organization (maximum of two) OR to the PECSF Fund Supported Pool of charities in your region. To see which charities are in the PECSF Fund Supported Pool, <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">click on your region</a>.</p><br /><p><em>Before registering for your Long Service Award, you will first need to view the list of <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">PECSF charities by Region</a>.</em></p><br /><p><em>Once you have chosen a charity in your region, note the <strong>PECSF ID# and charity name</strong> as you will need to provide this information when you register. </em></p><br /><p><strong>A commemorative certificate noting your charitable contribution will be presented to you at the Long Service Awards ceremony in the fall.</strong></p><p><em><small>Note: Charitable tax receipts are <strong>not</strong> issued for Long Service Award donations</small></em></p></span>' +
        '</div>' +
        // Certificate and certificate text box
        '<div id = "lsa_certificate_and_textbox_div">' +
          // Certificate - comes with all 25 year gifts
          '<span id="info_25_year_certificate"><img src="/sites/default/files/bg/image/2015/0224/lsacertificategeneric-thumb.jpg" alt="25 year certificate" id="image_25_year_certificate"><p>The 25 year milestone award comes with an <em><strong>optional</strong></em> certificate of service: </p><br /></span>' +
          // Create a radial button to let the user select if they would, or would not like a certificate.
         // '<form name="_25_certificate_choice" required="required" id="certificate_choice">' +
            '<input type = "radio" name="certificate" value="yes" checked="checked" id="_25_certificate_yes">Yes please – I would like a framed certificate, in addition to my chosen award above. <br />' +
            '<input type = "radio" name="certificate" value="no" id="_25_certificate_no">No thanks – I do not require a certificate. <br />' +
          //'</form>' +
          // Create a text box, make it required for 25 years
          //'<p>This is how your name will appear on the certificate, please make any changes you require</p>'+
          '<input id="_25_year_certificate_text_box" type="text" name="_25_certificate_box" maxlength="255" style="width:300px" required="required" display="none"></input>' +
        '</div>',
        // buttons options, if not than Next or Back then we need to put quotes around it
        buttons: { 'Accept': 1 },
        /**
         * Submit function
         * @param  {Object} f - Holds form data that user has chosen
         */
        submit:function(e,v,m,f){
          // List of arguements that can be used in order to save gift value to our LSA form
          gift_choice_populate_form(f);
          e.preventDefault();

          // We are done with this pop
          $.prompt.close();
        }
      },
    };

    // Call the correct impromptu variable
    $.prompt(gift_chooser);
    // initial setup for images/info
    image_choices();
    more_info_choices();
    certificate_name();

        // Helper function to only show the image for the current selection
    $("select#gift_selection_box").change(function() {
      image_choices();
      more_info_choices();
      if($('select#gift_selection_box').val() == "PECSF Fund"){
        // Every 25 year gift comes with a certificate this should always be shown
        $('#info_25_year_certificate').hide();
        $('#image_25_year_certificate').hide();
        $('#lsa_certificate_and_textbox_div').hide();
        $('#edit-field-lsa-certificate-ordered-und').prop("checked", false);
        $('#_25_certificate_no').prop('checked', true);
      } else {
        // Every 25 year gift comes with a certificate this should always be shown
        $('#info_25_year_certificate').show();
        $('#image_25_year_certificate').show();
      }
    });
  }

 /**
 * Function for those who choose 30 years of service
 * Includes impromptu library
 * Updates form fields for /career/long-service-awards/form
 */

  function _30year() {
    // Using the impromptu library for this: http://trentrichardson.com/Impromptu/
    var gift_chooser = {
      state0: {
        title: 'Congratulations on 30 years!',
        // All HTML in one long string - pretty much any html tags can go here, and will be replicated in the popup.
        html: '<p>Please use the drop-down menu to view and choose your award from the list below. Once you have chosen your award, click on "Accept" to return to the LSA form.<p>'+
       /**
         * Select List
         */
        '<label>Award Options: <select name="_30_year_option" id="gift_selection_box"><br />' +
          // Collande Clock
          '<option value="Collande Clock" name="collande_clock" id="30_gift_collande_clock">Collande Clock</option>' +
          // Sherpa blanket
          '<option value="Appalacian Sherpa Blanket" name="sherpa_blanket" id="30_gift_sherpa_blanket">Appalacian Sherpa Blanket</option>' +
          // RHV Orca Sunset painting
          '<option value="Roy Vickers Print - Tofino Sunrise" name="rhv_print_sunrise" id="30_gift_rhv_print_sunrise">"Tofino Sunrise" framed art print</option>' +
          // Sterling earrings
          '<option value="Solid Sterling Drop Earrings" name="sterling_earrings" id="30_gift_sterling_earrings">Sterling silver drop earrings</option>' +
          // PECSF donation
          '<option value= "$150.00 PECSF Charitible Donation" name="provincial_employees_community_services_fund" id="25_pecsf">Charitable Donation</option>' +
        '</select></label>' +
        /**
         * Image List
         * NOTE: image id must match option "name" variable preceeded by image_ for the image to show.
         */
        '<div id="lsa_gift_images_div">' +
          // Collande Clock
          '<img src="/sites/default/files/lsa_2015/30_collande_clock.jpg" alt="Collande Clock" id="image_collande_clock"><br />'+
          // Maglight and Flashlight
          '<img src="/sites/default/files/lsa_2015/30_sherpa_blanket.png" alt="Image of appalachian sherpa blanket" id="image_sherpa_blanket"><br />' +
          // RHV Orca Sunset painting
          '<img src="/sites/default/files/lsa_2015/30_tofino_sunrise.jpg" alt="Roy Henry Vickers Tofino Sunrise print" id="image_rhv_print_sunrise"><br />' +
          // Sterling Earrings
          '<img src="/sites/default/files/bg/image/2015/0224/30YearEarrings.jpg" alt="Solid Sterling Drop Earrings" id="image_sterling_earrings"><br />' +
          // PECSF donation
          '<img src="/sites/default/files/lsa_2015/25_pecsf.jpg" alt="PECSF donation image" id="image_provincial_employees_community_services_fund"><br />' +
        '</div>' +
        /**
         * More info list
         * NOTE: related span id must match option "name" variable preceeded by info_ for the image to show.
         */
        '<div id = "lsa_more_info_div">' +
          // Blue ball point pen
          '<span id="info_collande_clock"><p>Bold optical crystal, carriage-style clock with black glass center panel.</p><p>White dial with black Roman numerals and hour markers surrounded by a polished silver-tone bezel.</p><br /><p><strong>Dimensions: </strong>6.75"H (17 cm) by 6.25"W (16 cm)</p><p><strong>Detail:</strong> Engraved plate on front of clock: 30 years of service</p></span>' +
          //Maglight and Flashlight
          '<span id="info_sherpa_blanket"><p>Ultimate high-end plush blanket: faux suede on one side and soft 270g Sherpa fleece on the other.</p><br /><p>Size:  50" H X 60" L</p><p>Embroidered on corner: 30 years</p></span>' +
          // RHV Orca Sunset painting
          '<span id="info_rhv_print_sunrise"><p>By artist Roy Henry Vickers.</p><br /><p> <a href="http://www.royhenryvickers.com/reproductions/product/820" target="_blank">Website</a></p><br /><p>Size: 14  inches x 11 inches (approx.)</p><p>Engraved plate in matting : 30 years of service</p></span>' +
          // Sterling Earrings
          '<span id="info_sterling_earrings"><p>By Nancy Dawson and Vincent Henson, Silver Eagles Design Studio, Alert Bay, Vancouver Island.</p><br /><p>Each pair is hand-made by the artists.</p><br /><p><strong>Note:</strong> these earrings are designed to coordinate with the 35 year sterling silver Aboriginal bracelet</p></span>' +
          // PECSF
          '<span id="info_provincial_employees_community_services_fund"><p>In lieu of receiving a Long Service Award, you may opt to make a charitable donation via <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf" target="_blank">PECSF</a>. You may choose to donate to any registered charitable organization (maximum of two) OR to the PECSF Fund Supported Pool of charities in your region. To see which charities are in the PECSF Fund Supported Pool, <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">click on your region</a>.</p><br /><p><em>Before registering for your Long Service Award, you will first need to view the list of <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">PECSF charities by Region</a>.</em></p><br /><p><em>Once you have chosen a charity in your region, note the <strong>PECSF ID# and charity name</strong> as you will need to provide this information when you register. </em></p><br /><p><strong>A commemorative certificate noting your charitable contribution will be presented to you at the Long Service Awards ceremony in the fall.</strong></p><p><em><small>Note: Charitable tax receipts are <strong>not</strong> issued for Long Service Award donations</small></em></p></span>' +
        '</div>',
        // buttons options, if not than Next or Back then we need to put quotes around it
        buttons: { 'Accept': 1 },
        submit:function(e,v,m,f){
          // List of arguements that can be used in order to save gift value to our LSA form
          gift_choice_populate_form(f);

          e.preventDefault();

          $.prompt.close();
        }
      },
    };

    // Call the correct impromptu variable - this will always be 25 years in this function.
    $.prompt(gift_chooser);
    image_choices();
    more_info_choices();
    // Helper function to only show the image for the current selection
    $("select#gift_selection_box").change(function() {
      image_choices();
      more_info_choices();
    });
  }

/**
* Function for those who choose 35 years of service
* Includes impromptu library
* Updates form fields for /career/long-service-awards/form
*/

  function _35year() {

    // Using the impromptu library for this: http://trentrichardson.com/Impromptu/
    var gift_chooser = {
      state0: {
        title: 'Congratulations on 35 years!',

        // All HTML in one long string - pretty much any html tags can go here, and will be replicated in the popup.
        html: '<p>Please use the drop-down menu to view and choose your award from the list below. Once you have chosen your award, click on "Accept" to return to the LSA form.<p>'+
        /**
         * Select List
         */

        // Choices
        '<label>Award Options: <select name="_35_year_option" id="gift_selection_box"><br />' +
          // Binoculars
          '<option value="Bushnell Compact Binoculars" name="bushnell_binoculars" id="35_bushnell_binoculars"> Bushnell Excursion compact binoculars HD</option>' +
          // Watch
          '<option value="Bulova Watch" name="bulova_watch" id="35_bulova_watch">Bulova Watch</option>' +
          // Bracelet
          '<option value="Solid Sterling Silver Aboriginal Bracelet" name="aboriginal_bracelet" id="35_aboriginal_bracelet"> Sterling silver Aboriginal bracelet </option>' +
          // Glass Vase
          '<option value="Hand-Blown Glass Vase by Robert Held" name="glass_vase" id="35_glass_vase">“Blue Flower Bouquet” glass vase</option>' +
          // PECSF donation
          '<option value= "PECSF Fund" name="provincial_employees_community_services_fund" id="25_pecsf">Charitable Donation</option>' +
        '</select></label>' +
        // Mens or womens watch
        '<div id="mens_womens">' +
          '<p>Please choose:</p>' +
          '<label><input type="radio" name="Mens_Womens" value="Ladies\'" id="35_bulova_womens" > Ladies\' </label>' +
          '<label><input type="radio" name="Mens_Womens" value="Men\'s" id="35_bulova_mens"> Men\'s </label>' +
        '</div>' +
        // Watch Type
        '<div id="watch_type">' +
          '<p>Please choose the type of watch you would like</p><br />' +
          '<label>Options: <select name="_35_year_bulova_watch_type" id="Bulova_type_selection_box"><br />' +
            '<option value="default" name="default" id="default_choice"> - Choose a watch type - </option>' +
            '<option value="Gold" name="Gold Watch" id="35_bulova_gold_watch"> Gold Watch </option>' +
            '<option value="Silver" name="Silver Watch" id="35_year_bulova_silver_watch"> Silver Watch </option>' +
          '</select></label><br />' +
        '</div>' +
        // If silver, two toned or silver
        '<div id="face_type">' +
          '<p>Which type of watch face would you like on your silver watch?</p>' +
          '<label><input type="radio" name="silver_face_type" value="Silver" id="35_bulova_silver_face"> Silver' +
          '<label><input type="radio" name="silver_face_type" value="Two-toned" id="35_bulova_two_toned_face">Two Toned</label>' +
        '</div>' +
        //  If gold, gold/black or brown strap?
        '<div id="strap_type">' +
          '<p> Select the strap you would like for your watch </p>' +
          '<label><input type="radio" name="gold_strap_type" value="Gold" id="35_bulova_gold_strap">Gold</label>'+
          '<label><input type="radio" name="gold_strap_type" value="Brown Leather" id="35_bulova_brown_strap">Brown Leather</label>'+
          '<label><input type="radio" name="gold_strap_type" value="Black Leather" id="35_bulova_black_strap">Black Leather</label>'+
        '</div>' +
        '<div id="watch_engravement_text_box">' +
          '<p id="engravement_text"></p>' +
          '<label><span style="color:red;"><strong>*</strong></span>Engravement: <input type="text" name="engravement_pop" value="" id="engravement_pop_text" maxlength="27"></label><br />' +
        '</div>' +
         //Aboriginal bracelet size choices
        '<div id="bracelet_size">' +
          '<p> Select the size of bracelet you would like. </p>' +
          '<label><input type="radio" value="size A" id="35_bracelet_size_a" name="size_bracelet">Size A: fits 6 1/2 to 7 1/2 inch wrists.</label>' +
          '<label><input type="radio" value="size B" id="35_bracelet_size_b" name="size_bracelet">Size B: fits 7 1/2 to 8 1/2 inch wrists.</label>' +
        '</div>' +

        /**
         * Image List
         * NOTE: image id must match option "name" variable preceeded by image_ for the image to show.
         */
        '<div id="lsa_gift_images_div">' +
          // Bulova watch
          '<img src="/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg" alt="Bulova Gold Watch" id="image_bulova_watch_1">'+
          '<img src="/sites/default/files/bg/image/2015/0224/35watchleathertb.jpg" alt="Bulova Gold Watch with Leather strap" id="image_bulova_watch_2"> ' +
          '<img src="/sites/default/files/bg/image/2015/0224/35watchsilverwtb.jpg" alt="Bulova Silver Watch, Silver Face" id="image_bulova_watch_3">' +
          '<img src="/sites/default/files/lsa_2015/35_watch_silver_gold.png" alt="Bulova Silver Watch, two-toned face" id="image_bulova_watch_4">' +
          // Bushnell Compact Binoculars
          '<img src="https://gww.gov.bc.ca/sites/default/files/bg/image/2015/0224/picofBino2016.jpg" alt="bushnell compact binoculars" id="image_bushnell_binoculars">' +
          // Bracelet Picture
          '<img src="/sites/default/files/lsa_2015/35_bracelet.jpg" alt="Sterling Silver Aboriginal Bracelet" id="image_aboriginal_bracelet">' +
          // Vase Picture
          '<img src="/sites/default/files/lsa_2015/35_rh_vase_2016.jpg" alt=="Glass Vase" id="image_glass_vase">' +
          // PECSF donation
          '<img src="/sites/default/files/lsa_2015/25_pecsf.jpg" alt="PECSF donation image" id="image_provincial_employees_community_services_fund"><br />' +
        '</div>' +

        /**
         * More info list
         * NOTE: related span id must match option "name" variable preceeded by info_ for the image to show.
         */
        '<div id = "lsa_more_info_div">' +
          // Bulova watch
          '<span id="info_bulova_watch"><br /><p>Watch features BC Coat of Arms printed on dial.</p><br /><p>This finely-made watch comes in a variety of choices, gold, silver, black or brown leather, and a two-toned watch face.</p><br /><p><strong>Detail:</strong> Engraved with name of recipient and “35 years of service” on back of watch</p></span>' +
          // Bushnell binoculars
          '<span id="info_bushnell_binoculars"><br /><p>Bushnell Roof Prism Binocular: Featuring BaK-4  Roof Prisms with PC-3  Phase Coating, 8 x 42 mm, Field of View 426 yards, Fully Multicoated Optics, 100 % Waterproof/Fogproof , Light-Weight Open Bridge Design, Soft Grip Thumb Notch.</p><br /><p>Size: 8 x 42 mm</p><p><strong>Note:</strong> due to the nature of this award, engraving is not possible</p></span>' +
          // Aboriginal Bracelet
          '<span id="info_aboriginal_bracelet"><br /><p> Each bracelet is hand made by Nancy Dawson, Silver Eagles Design Studio, Alert Bay, Vancouver Island.</p><br /><p>Solid sterling silver cuff bracelet, ¾ inch wide.</p><br /><p>Size A: fits: 6 ½" - 7 ½" wrist</p><p>Size B: fits 7 ½" -  8 ½" wrist</p><p>Engraved plate on box: 35 years of service.</p></span>' +
          // Glass Vase
          '<span id="info_glass_vase"><br /><p>Hand-blown glass vase made in Parksville, B.C. by Robert Held.</p><br /><p>Website <a href="http://robertheld.com/" target = "_blank">http://robertheld.com/</a> </p><br /><p>Size:11.5" H</p><p><strong>Note:</strong> Due to the nature of this gift, engraving is not possible.</p></span>' +
          // PECSF
          '<span id="info_provincial_employees_community_services_fund"><p>In lieu of receiving a Long Service Award, you may opt to make a charitable donation via <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf" target="_blank">PECSF</a>. You may choose to donate to any registered charitable organization (maximum of two) OR to the PECSF Fund Supported Pool of charities in your region. To see which charities are in the PECSF Fund Supported Pool, <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">click on your region</a>.</p><br /><p><em>Before registering for your Long Service Award, you will first need to view the list of <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">PECSF charities by Region</a>.</em></p><br /><p><em>Once you have chosen a charity in your region, note the <strong>PECSF ID# and charity name</strong> as you will need to provide this information when you register. </em></p><br /><p><strong>A commemorative certificate noting your charitable contribution will be presented to you at the Long Service Awards ceremony in the fall.</strong></p><p><em><small>Note: Charitable tax receipts are <strong>not</strong> issued for Long Service Award donations</small></em></p></span>' +
        '</div>',
        // buttons options, if not than Next or Back then we need to put quotes around it
        buttons: { 'Accept': 1 },
        submit:function(e,v,m,f){

          gift_choice_populate_form(f);

          e.preventDefault();

          $.prompt.close();
        }
      },
    };

    // Call the correct impromptu variable .
    $.prompt(gift_chooser);

    image_choices_35_year();
    more_info_choices();
    watch_choices();
    check_form();
    // Don't allow submission on this page until everything is filled out - This will be made available on any other choice, or when the engraving portion is filled in.

    $("button.jqibutton.jqidefaultbutton").on('click', function() {
      check_form();
    });

    $('form.jqiform').change(function() {
      image_choices_35_year();
      more_info_choices();
      // Special 35 year function to show proper watch fields - and set "required"
      watch_choices();
      check_form();
    });

    $('form.jqiform').keyup(function() {
    //  image_choices_35_year();
    //  more_info_choices();
    // Special 35 year function to show proper watch fields - and set "required"
   //   watch_choices();
      check_form();
    });

    //Need to catch the case if user swaps watch type
    $("#Bulova_type_selection_box").change(function() {
      reset_fields();
    });

    $("select#gift_selection_box").change(function() {
      // If the selection changes, reset the fields
      //$('.jqiform').trigger("reset");
    });

    // TODO: We need to pay attention to all fields on the watch portion of the form, so more handlers:

  }
/**
* Function for those who choose 40 years of service
* Includes impromptu library
* Updates form fields for /career/long-service-awards/form
*/

  function _40year() {
    // Using the impromptu library for this: http://trentrichardson.com/Impromptu/
    var gift_chooser = {
      state0: {
        title: 'Congratulations on 40 years!',
        // All HTML in one long string - pretty much any html tags can go here, and will be replicated in the popup.
        html: '<p>Please use the drop-down menu to view and choose your award from the list below. Once you have chosen your award, click on "Accept" to return to the LSA form.<p>'+
        // Create the select list, remember name and id, both are used.
        '<label>Award Options: <select name="_40_year_option" id="gift_selection_box"><br />' +
          // Mantle Clock
          '<option value="Napolean Beauty Ergo Mantle Clock" name="mantle_clock" id="40_gift_mantle_clock">“Napolean Beauty” Ergo Mantle Clock</option>' +
          // Diamond earrings
          '<option value="14kt Diamond Earrings" name="diamond_earrings" id="40_diamond_earrings">Genuine Diamond Stud Earrings: 14 kt white gold</option>' +
          // Diamond pendant
          '<option value="14kt White Gold Diamond Stud Earrings" name="diamond_pendant_and_chain" id="40_diamond_pendant_and_chain">Genuine Round  Diamond pendant and chain  - 10 kt  white gold </option>' +
          // Glass bowl
          '<option value="Hand-Blown Glass Bowl by Robert Held" name="glass_bowl" id="40_glass_bowl">Hand-blown glass bowl</option>' +
          // MD Print
          '<option value="Michaela Davidson Print - Sunbreakers" name="md_print" id="40_md_print">“Sun Breakers” - framed art print </option>' +
          // PECSF donation
          '<option value= "$400.00 PECSF Charitible Donation" name="provincial_employees_community_services_fund" id="25_pecsf">Charitable Donation</option>' +
        '</select></label>' +
        /**
         * Image List
         * NOTE: image id must match option "name" variable preceeded by image_ for the image to show.
         */
        '<div id="lsa_gift_images_div">' +
          // Mantle Clock
          '<img src="/sites/default/files/lsa_2015/40_clock_2016.jpg" alt="Ergo Mantle clock \"Napolean Beauty\"" id="image_mantle_clock"><br />'+
          // Diamond Earrings
          '<img src="/sites/default/files/lsa_2015/40_earrings.jpg" alt="Genuine Daimond Stud earrings" id="image_diamond_earrings"><br />' +
          // Glass bowl
          '<img src="/sites/default/files/bg/image/2015/0224/40vasetb.jpg" alt="Robert Helpd Blown Glass Bowl" id="image_glass_bowl"><br />' +
          // MD Print
          '<img src="/sites/default/files/lsa_2015/40_MD_print.jpg" alt="Framed Art print" id="image_md_print"><br />' +
          // PECSF donation
          '<img src="/sites/default/files/lsa_2015/25_pecsf.jpg" alt="PECSF donation image" id="image_provincial_employees_community_services_fund"><br />' +
          // Diamond pendant
          '<img src="/sites/default/files/lsa_2015/40_diamond_pendant.png" alt="Image of diamond pendant" id="image_diamond_pendant_and_chain"><br />' +
        '</div>' +
        /**
         * More info list
         * NOTE: related span id must match option "name" variable preceeded by info_ for the image to show.
         */
        '<div id = "lsa_more_info_div">' +
          // Mantle Clock
          '<span id="info_mantle_clock"><p>This beautiful clock features a wood frame in solids and veneers in a warm oak finish with burl accents. A brass finish bezel surrounds the dial. It has very rich sounding chimes - choose from 4 chimes with a simple switch on the movement: <ul><li>Quarterly Westminster</li> <li>Quarterly Ava Maria</li> <li>Hourly Westminster</li> <li>Hourly/half hour strike</li></ul></p><br /><p>Size: 20" x 10"</p><p><a href="http://www.howardmiller.com/" target="_blank">Website</a></p></span>' +
          // Diamond Earrings
          '<span id="info_diamond_earrings"><p>White gold stud earrings Round Brilliant cut diamonds .25 ct. tw.</p><br /><p><strong>Detail:</strong> 40 Years of Service plaque on lid of box</p></span>' +
          // Glass Bowl
          '<span id="info_glass_bowl"><p>Hand-blown glass vase made in Parksville, B.C. by Robert Held. Website <a href="http://robertheld.com/" target = "_blank">http://robertheld.com/ </a></p><br /><p><strong>Size:</strong> 7" H</p><br /><p><strong>Note:</strong> due to the nature of this award, engraving is not possible.</p></span>'+
          // MD print
          '<span id="info_md_print"><p>By artist Michaela Davidson, Duncan and Lake Cowichan, B.C.</p><br /><p>Website <a href="http://michaeladavidsonart.com/" target = "_blank">http://michaeladavidsonart.com/</a> </p><br /><p>Size: 16"W x 14"H (approx.)</p><p>Engraved plate in matting: 40 years of service</p></span>' +
          // Diamond Pendant
          '<span id="info_diamond_pendant_and_chain"><p>White gold, four claw pendant and 18 inch Singapore chain.</p><p>Round Brilliant cut diamonds .20 ct. tw.</p><br /><p>Engraved plate on box: 40 years of service</p></span>'+
          // PECSF
          '<span id="info_provincial_employees_community_services_fund"><p>In lieu of receiving a Long Service Award, you may opt to make a charitable donation via <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf" target="_blank">PECSF</a>. You may choose to donate to any registered charitable organization (maximum of two) OR to the PECSF Fund Supported Pool of charities in your region. To see which charities are in the PECSF Fund Supported Pool, <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">click on your region</a>.</p><br /><p><em>Before registering for your Long Service Award, you will first need to view the list of <a href="http://www2.gov.bc.ca/gov/content/careers-myhr/about-the-bc-public-service/corporate-social-responsibility/pecsf/donate/choose-your-charity#charity-regions" target="_blank">PECSF charities by Region</a>.</em></p><br /><p><em>Once you have chosen a charity in your region, note the <strong>PECSF ID# and charity name</strong> as you will need to provide this information when you register. </em></p><br /><p><strong>A commemorative certificate noting your charitable contribution will be presented to you at the Long Service Awards ceremony in the fall.</strong></p><p><em><small>Note: Charitable tax receipts are <strong>not</strong> issued for Long Service Award donations</small></em></p></span>' +
        '</div>',
        // buttons options, if not than Next or Back then we need to put quotes around it
        buttons: { 'Accept': 1 },
        submit:function(e,v,m,f){
          // List of arguements that can be used in order to save gift value to our LSA form
          gift_choice_populate_form(f);
          e.preventDefault();

          $.prompt.close();
        }
      },
    };

    // Call the correct impromptu variable - this will always be 25 years in this function.
    $.prompt(gift_chooser);
    image_choices();
    more_info_choices();
    // Helper function to only show the image for the current selection
    $("select#gift_selection_box").change(function() {
      image_choices();
      more_info_choices();
    });
  }



/**
 * This is a helper function that uses return object to populate the lsa form
 */

function gift_choice_populate_form(gifts){
  // List
  var gift_name;
  var gift_id_number;
  var full_gift_name;
  //console.log(gifts);

  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 25){
    gift_name = gifts._25_year_option;
    certificate_choice = gifts.certificate;
    var cert_choice='';
    if(certificate_choice == "yes"){
      cert_choice = "Framed Certificate and ";
      $('#edit-field-lsa-certificate-ordered-und').prop("checked", true);
    } else {
      cert_choice='';
      $('#edit-field-lsa-certificate-ordered-und').prop("checked", false);
    }
    // This gift must have a certificate name for recipient
    //$('#field-lsa-25year-certificatename-add-more-wrapper').show();
    //$("input#edit-field-lsa-25year-certificatename-und-0-value").prop("required", "required");
    // Get proper wording
    switch(gift_name) {
      case "Cross Starry Blue ballpoint pen":
        g_choice = "Cross 'Starry Blue' Ballpoint Pen";
        break;
      case "Cross Tablet holder":
        g_choice = "Leather Tablet Holder with Notepad";
        break;
      case "Sterling Silver and White Pearl Earrings":
        g_choice = "Sterling Silver White Pearl Earrings";
        break;
      case "Passport and Luggage tag set":
        g_choice = "Leather Passport and Luggage Tag Set";
        break;
      case "PECSF Fund":
        g_choice = "$75.00 PECSF Charitible Donation";
        // No certificate, so lets send this back now
        full_gift_name  = "25 - $75.00 PECSF Charitible Donation";
        break;
      default :
        g_choice = "Please try again.";
        break;
    }
    if(cert_choice){
      full_gift_name = "25 - " + cert_choice + g_choice;
    } else if(full_gift_name == '25 - $75.00 PECSF Charitible Donation'){
      //do nothing, already filled this in above.
    } else {
      full_gift_name = "25 - " + g_choice + " - No Certificate";
    }
    // Put the certificate info into the main form
    $('#edit-field-lsa-25year-certificatename-und-0-value').val($('#_25_year_certificate_text_box').val());
  }

  // 30 year gift population
  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 30){
    gift_name = gifts._30_year_option;
    full_gift_name = "30 - " + gift_name;
  }


  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 35){
    gift_name = gifts._35_year_option;
    if(gift_name == 'Solid Sterling Silver Aboriginal Bracelet'){
      full_gift_name = "35 - Sterling Silver Bracelet - " + gifts.size_bracelet;
    }
    if(gift_name == 'Bushnell Compact Binoculars'){
      full_gift_name = "35 - Bushnell Compact Binoculars";
    }
    if(gift_name == "Bulova Watch"){
      var watch_specific_type;
      if(gifts._35_year_bulova_watch_type == "Gold"){
        watch_specific_type = gifts.gold_strap_type + " Strap";
      } else {
        watch_specific_type = gifts.silver_face_type + " Face";
      }
      full_gift_name = "35 - " + gifts.Mens_Womens + " " + gifts._35_year_bulova_watch_type + " Watch with " + watch_specific_type;
    }
    if(gift_name == "Hand-Blown Glass Vase by Robert Held"){
      full_gift_name = "35 - " + gifts._35_year_option;
    }
    if(gift_name == "PECSF Fund"){
      full_gift_name = "35 - $300.00 PECSF Charitible Donation";
    }
    // Fill in Engravement if it was an option
    if($("#engravement_pop_text").prop("value")!== ""){
      $("#edit-field-lsa-engravement-und-0-value").val($("#engravement_pop_text").prop("value"));
    }
  }


  // 40 year gift population
  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 40){
    gift_name = gifts._40_year_option;
    full_gift_name = "40 - " + gifts._40_year_option;
  }

       // 45 year gift population
  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 45){
    gift_name = "45 - Choice TBC";
    full_gift_name = "45 - Choice TBC";
  }
  // 50 year gift population
  if($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 50){
    gift_name = "50 - Choice TBC";
    full_gift_name = "50 - Choice TBC";
  }

  // Populate the gift id box
  gift_list_object = gift_list_complete();

  // Match gift to list to get id
  $.each(gift_list_object, function(key, value){
    if (value == full_gift_name){
      gift_id_number = key;
    }
  });

      // Last years recipients will always have the same award and award id number
  if ($("input[name='field_lsa_register_last_year[und]']:checked").val() == 1){
    full_gift_name = "2015 Recipient - award received";
    gift_id_number = 1;
  }

  // Populate gift choice text and id with data and close this prompt
  $('#edit-field-lsa-award-und-0-value').show();
  $('#edit-field-lsa-award-und-0-value').val(full_gift_name);
  $('#edit-field-lsa-award-id-und-0-value').val(gift_id_number);
  // Check if this is a pecsef donation, if it is, run a function to figure out values etc.
  switch(true){
    case gift_id_number == 11:
      set_pecsef(25);
      break;
    case gift_id_number == 17:
      set_pecsef(30);
      break;
    case gift_id_number == 33:
      set_pecsef(35);
      break;
    case gift_id_number == 40:
      set_pecsef(40);
      break;
    case gift_id_number == 42:
      set_pecsef(45);
    break;
    case gift_id_number == 44:
      set_pecsef(50);
    break;
    default:
      // Not pecsf, so make sure this is hidden and turned off.
      $('#pecsf-fields').hide();
    break;
  }
}

/** Helper function to set PECSEF options anv values
 *
 */
  function set_pecsef(year){
    // Show and open pecsf block
    $('#pecsf-fields').slideDown('slow');
    switch(true){
      case year == 25:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$75.00');
        break;
      case year == 30:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$150.00');
        break;
      case year == 35:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$300.00');
        break;
      case year == 40:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$400.00');
        break;
      case year == 45:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$450.00');
        break;
      case year == 50:
        $('#edit-field-lsa-donation-amount-und-0-value').val('$500.00');
        break;
    }
  }




/**
 * Helper function to populate 25_year certificate with users name
 */
 function certificate_name(){
  $('#_25_year_certificate_text_box').val($('#edit-field-lsa-first-name-und-0-value').val() + ' ' + $('#edit-field-lsa-last-name-und-0-value').val());
  $('#_25_year_certificate_text_box').hide();
  //console.log($('#_25_year_certificate_text_box').val());
 }


/**
 * Helper function that sends user to proper year gift choices
 * Years 45 & 50 handled in atwork_lsa_module
 */
  function gift_choices() {
    var gift_year_choice = $('input[name="field_lsa_years_of_service[und]"]:checked').val();
    switch (gift_year_choice) {
      case '25':
        _25year();
        break;
      case '30':
        _30year();
        break;
      case '35':
        _35year();
        break;
      case '40':
        _40year();
        break;
      case '45':
        gift_choice_populate_form("45");
        break;
      case '50':
        gift_choice_populate_form("50");
        break;
      default:
        alert("Something went wrong, please try your selection again.");
    }
  }

/**
 * Helper function that hides all images in the gift choice form, except for the one currently selected.
 */
  // This hides all but the applicable image - uses 'name' and 'id' from html.
  function image_choices() {
    // Get the proper image id - this requires standardized id nomiclature for any added image (#image_[name])
    var selected_image=($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name")));
    // Hide everything and...
    $('#lsa_gift_images_div img').hide();
    // Show only the image that goes with the selection
    selected_image.show();
  }

/**
 * Helper function that hides all "more information" paragraphs from form, except for the one currently selected
 *
 */
  // This hides all but teh applicable information <p>
  function more_info_choices() {
    var selected_info=($('#info_' + $("select#gift_selection_box").find('option:selected').attr("name")));
    $('#lsa_more_info_div span').hide();
    selected_info.show();
  }

/**
 * Helper function that hides all images in the gift choice form, except for the one currently selected.
 * Special case for 35 year (multi-picture)
 */
  // This hides all but the applicable image - uses 'name' and 'id' from html.
  function image_choices_35_year() {


    // Strip Engravement text, we will fill it out again if applicable
    $('#edit-field-lsa-engravement-und-0-value').val('');
    $('#edit-field-lsa-engravement-und-0-value').hide();
    $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').hide();

    // Get the proper image id - this requires standardized id nomiclature for any added image (#image_[name])
    var selected_image=($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name")));
    // Hide everything and...
    $('#lsa_gift_images_div img').hide();
    // If watch, show watch, print engravement to form
    if($("select#gift_selection_box").find('option:selected').attr("name") == "bulova_watch"){
      $('#lsa_gift_images_div img').hide();
      // Prepare the proper image names and....
      selected_image_1 = ($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name") + '_1'));
      selected_image_2 = ($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name") + '_2'));
      selected_image_3 = ($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name") + '_3'));
      selected_image_4 = ($('#image_' + $("select#gift_selection_box").find('option:selected').attr("name") + '_4'));

      // Show them
      selected_image_1.show();
      selected_image_2.show();
      selected_image_3.show();
      selected_image_4.show();
      $('#edit-field-lsa-engravement-und-0-value').show();
      $('.form-item.form-type-textfield.form-item-field-lsa-engravement-und-0-value').show();
    } else {
      // Show only the image that goes with the selection
      selected_image.show();
    }
  }

  /**
   * Helper function that hides/shows fields applicable to the watch choice
   * Also sets/removes "Required" status of the fields
   */

  function watch_choices() {
    $('#mens_womens').hide();
    $('#watch_type').hide();
    $('#strap_type').hide();
    $('#face_type').hide();
    $('#watch_engravement_text_box').hide();
    $('#bracelet_size').hide();
    // Check if we are actually looking at a watch, or else leave
    if($("select#gift_selection_box").find('option:selected').attr("name") == "bulova_watch"){
            // Set up the form for watches
      // This is a watch, so show mens/ womens choice
      $('#mens_womens').show();
      // Set mens/womens and engrave to required - will be needed either way
      $('input[name=Mens_Womens]:radio').prop("required", true);
      $('#engravement_pop_text').prop("required", true);

      // These are not prechecked so we can use a handler on them - if one is chosen, show watch type choice
      if($('input[name="Mens_Womens"]').is(':checked')){
        // Women are not allowed as many chracters for their engravement - so we nead to change max and message.
        if($('input[name="Mens_Womens"]:checked').prop("value") == "Men\'s"){
          $("#engravement_text").replaceWith('<p id="engravement_text">Please enter your name how you would like it engraved on your watch. <strong>*NOTE:</strong> 33 character limit</p>');
          $('#engravement_pop_text').prop("maxlength", 33);
        } else {
          $("#engravement_text").replaceWith('<p id="engravement_text">Please enter your name how you would like it engraved on your watch. <strong>*NOTE:</strong> 27 character limit</p>');
          $('#engravement_pop_text').prop("maxlength", 27);
          if($("#engravement_pop_text").val().length>27){
            // Need to reduce length of entered values if we switch to ladies watch after mens watch.
            $('#engravement_pop_text').val($("#engravement_pop_text").val().substring(0,27));
          }
        }
        // show type chooser and make it required
        $('#watch_type').show();
        $('#Bulova_type_selection_box').prop("required", true);

      }
      // This is a watch and we know the type, so now show/hide special choices depending on teh watch. Reset if the type is changed.
      if($('select#Bulova_type_selection_box').find('option:selected').prop("value") == 'Gold'){
        $('#image_bulova_watch_3').hide();
        $('#image_bulova_watch_4').hide();
        // Show strap type choices for gold watches and make this required
        $('#strap_type').show();
        $('input[name=gold_strap_type]:radio').prop("required", true);
      } else if ($('select#Bulova_type_selection_box').find('option:selected').prop("value") == 'Silver'){
        // Show face type choices for silver watches adn make this required
        $('#image_bulova_watch_1').hide();
        $('#image_bulova_watch_2').hide();
        $('#face_type').show();
        $('input[name=silver_face_type]:radio').prop("required", true);
      }
      // Once all the available info is added, then we requre that the Engravement field is filled out.
      if($('input[name="gold_strap_type"]').is(':checked')){
        $('#watch_engravement_text_box').show();
        if($('input[name="gold_strap_type"]:checked').prop("value") == "Gold") {
          $('#image_bulova_watch_2').hide();
        } else {
          $('#image_bulova_watch_1').hide();
        }
      }

      if($('input[name="silver_face_type"]').is(':checked')){
        $('#watch_engravement_text_box').show();
        if($('input[name="silver_face_type"]:checked').prop("value") == "Silver") {
          $('#image_bulova_watch_4').hide();
        } else {
          $('#image_bulova_watch_3').hide();
        }
      }

      return;
    } else if($("select#gift_selection_box").find('option:selected').attr("name") == "aboriginal_bracelet"){
      $('#bracelet_size').show();
      // Clear all watch fields, turn off required
      reset_fields();
      // make size mandatory
      $('input[name="size_bracelet"]:radio').prop("required", true);
      // Hide all watch fields
      $('#mens_womens').hide();
      $('#watch_type').hide();
      $('#strap_type').hide();
      $('#face_type').hide();
      $('#watch_engravement_text_box').hide();
    } else {

      // Clear all watch fields, turn off required
      reset_fields();


    }
  }

  /**
   * Helper function that resets watch form if user switches watch type
   * Fixes issue where user could get stuck with a form that would not submit if they switched between gold and silver without filling in other selections
   * Also resets on gift choice change
   */

  function reset_fields() {
    // Reset all radio's except Ladie's/Mens radial as long as we are on the watch page
    $('.jqiform input[type="radio"]').each(function(){
      if($("select#gift_selection_box").find('option:selected').attr("name") == "bulova_watch") {
        if($(this).prop("name") == "Mens_Womens") {
          return;
        }
        if($(this).prop("name") == "engravement_pop"){
          return;
        }
      }
      if($("select#gift_selection_box").find('option:selected').attr("name") == "aboriginal_bracelet"){
        if($(this).prop("name") == "size_bracelet"){
          return;
        }
      }
      $(this).prop('checked', false);
      $(this).prop('required', false);
    });
    // Reset all forms
    $('.jqiform input[type="text"]').each(function(){
      $(this).val("");
      $(this).prop('required', false);
    });
    // Don't want to reset all 'select' forms or we will continually default to first gift choice.
    $('.jqiform select').each(function(){
      if($(this).prop("name")== "_35_year_option"){
        return;
      }
      // Need to reset teh watch type dropdown if we are not getting a watch
      if($("select#gift_selection_box").find('option:selected').attr("name")!= "bulova_watch"){
        $(this).find('option[value="default"]').prop('selected', 'selected');
      }
      //$(this).selectmenu('refresh', true);
      $(this).prop('required', false);
    });
  }



  /**
   * Helper function that loops through all form elements and ensures all "required" fields are filled in.
   */

  function validate_form() {

    // Need to spoof a validation handler
    var countValid = 0;
    var totalRequiredFields = 0;

    // go through every field on form to see if they are required
    $(':input[required]', '.jqiform').each( function() {
      // Keep track of required fields
      totalRequiredFields++;
      // If a text field, and filled in, it is valid
      if (($(this).prop('type')) == 'text' && this.value.trim() !== '') {
        countValid++;
      }
      // If a Radio, and one member of the group is checked, it is valid
      if (($(this).prop('type')) =='radio'){
        var radio_name = ($(this).prop("name"));
        if($('input[name='+ radio_name + ']:checked').length){
          countValid++;
        // Focus on fields that are not filled, return false
        } else {
          $(this).parent().parent().focus();
        //$(this).parent().css("border", "red solid 1px");
          return false;
        }
      }
      // Selection type goes here
      if($(this).prop('type') == 'select-one'){
        if(this.value.trim() !== ''){
          if(this.value.trim() !== 'default'){
            countValid++;
          } else {
            $(this.focus());
            return false;
          }
        }
      }
    });
    // If we have not validated all required fields, then return false
    if( countValid !== totalRequiredFields){
     return false;
    }
    // It all checks out - return true
    return true;
  }

  function check_form() {
    // TODO: create a validate function that checks if fields are filled in , then engrave
    var button_status = validate_form();
    //console.log(button_status);
    if(button_status === true){
      $("button.jqibutton.jqidefaultbutton").prop("disabled", false);
    } else {
      $("button.jqibutton.jqidefaultbutton").prop('disabled', true);
    }
  }


/**
 * Document ready controller,
 * Includes click handler for gift choice button created in "atwork_lsa.module"
 */
  $( document ).ready(function(){
    //jQuery.error = console.error;
    // User clicking on the jQuery created Choose Gift button will initiate this script
    $('input#gift_select').click(function () {
      gift_choices();
    });

    $('#edit-field-lsa-years-of-service-und').click(function () {
        if ($('input[name="field_lsa_years_of_service[und]"]:checked').val() == 45 || $('input[name="field_lsa_years_of_service[und]"]:checked').val() == 50){
        gift_choices();
      }
    });
  });

}(jQuery));
