/**
 * JS function for LSA Gift and key array
 * Drupal.jquery
 * Written by Thayne Werdal Feb 2016
 */

  function gift_list_complete() {
    const gift_list = {
	    1: "2018 Recipient - award received",
	    2: "25 - Choice TBC",
	    3: "25 - Framed Certificate and Cross pen",
	    //4: "25 - Cross 'Starry Blue' Ballpoint Pen - No Certificate",
		  4: "25 - Framed Certificate and Bugatti® writing case and tablet holder",
		  //6: "25 - Leather Tablet Holder with Notepad - No Certificate",
		  5: "25 - Framed Certificate and pearl earrings",
		  //8: "25 - Sterling Silver White Pearl Earrings - No Certificate",
		  6: "25 - Framed Certificate and passport and luggage tag set",
		  //10: "25 - Leather Passport and Luggage Tag Set - No Certificate",
		  7: "25 - Framed Certificate and $75.00 PECSF charitable donation",
		  8: "30 - Choice TBC",
		  9: "30 - Colonnade clock",
		  10: "30 - Appalachian Sherpa blanket",
		  11: "30 - Epiphany III framed Art Print",
		  12: "30 - Sterling silver earrings",
		  13: "30 - $150.00 PECSF charitable donation",
		  14: "35 - Choice TBC",
		  15: "35 - Bushnell Prime binoculars",
		  16: "35 - Blue flower bouquet glass vase",
		  17: "35 - Women's Gold Watch with Black Strap",
		  18: "35 - Women's Gold Watch with Brown Strap",
		  19: "35 - Women's Gold Watch with Gold Strap",
		  20: "35 - Women's Silver Watch with Silver Strap",
			21: "35 - Women's Silver Watch with Two-toned Strap",
			22: "35 - Women's Silver Watch with Black Strap",
			23: "35 - Women's Silver Watch with Brown Strap",
		  24: "35 - Men's Gold Watch with Black Strap",
		  25: "35 - Men's Gold Watch with Brown Strap",
		  26: "35 - Men's Gold Watch with Gold Strap",
		  27: "35 - Men's Silver Watch with Silver Strap",
			28: "35 - Men's Silver Watch with Two-toned Strap",
			29: "35 - Men's Silver Watch with Black Strap",
			30: "35 - Men's Silver Watch with Brown Strap",
		  31: "35 - Sterling Silver Bracelet - size A",
		  32: "35 - Sterling Silver Bracelet - size B",
		  33: "35 - $300.00 PECSF charitable donation",
		  34: "40 - Choice TBC",
		  35: "40 - Napolean Beauty ergo mantle clock",
		  36: "40 - Genuine diamond stud earrings",
		  37: "40 - Blue Flower Bouquet glass bowl",
		  38: "40 - Forest Cove framed art print",
		  39: "40 - Genuine diamond pendant and chain",
		  40: "40 - $400.00 PECSF charitable donation",
		  41: "45 - Choice TBC",
		  42: "45 - $450.00 PECSF charitable donation",
		  43: "50 - Choice TBC",
		  44: "50 - $500.00 PECSF charitable donation",
		  45: "Award already Sent",
      46: "Retroactive Award",
    };
    return gift_list;
  }

  function giftListImages() {
    const giftImages = {
      //"2016 Recipient - award received": ,
      //"Choice TBC": ,
      "Framed Certificate and Cross pen": 	{ "URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/cross-pen-2-thumb.jpg", "description":"This Cross® Calais chrome and blue lacquer rollerball pen is lightweight with a bold profile. It comes in a box with 25 Years engraved on the lid."},
      "Framed Certificate and Bugatti® writing case and tablet holder":  { "URI": "/sites/default/files/styles/node_image/public/bg/image/2019/0213/m000747150sc7.jpg", "description":"This recycled and synthetic leather case has <em>25 Years debossed</em> on the front. The zippered closure keeps your tablet secure during transport, and adjustable brackets hold most tablet models, including three sizes of iPad (tablet is not included). The cover includes a pocket for a smartphone, USB and pen holders, card slots, an ID window and writing pad. Size: 9\" W x 10 ¾ \“ H"},
      "Framed Certificate and passport and luggage tag set": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg","description":"This genuine black leather passport holder and luggage tag has 25 Years debossed on the front. It has a magnetic closure."},
      //"Leather Passport and Luggage Tag Set - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg",
      "Framed Certificate and pearl earrings": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg", "description":"These sterling silver, fresh water pearl earrings have an accent of gold. They are made in Vancouver, B.C. by Howling Dog Artisan Jewellery.<br>Note: Due to the nature of this award, engraving is not possible."},
      //"Sterling Silver White Pearl Earrings - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg",
      "Framed Certificate and $75.00 PECSF charitable donation": {"URI":"/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
      //"Choice TBC",
      "Colonnade clock": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/clock-thumb.jpg","description":"This bold optical crystal, carriage-style clock has In recognition of thirty years of service engraved on front plate. It features a black glass center panel and a white dial with black Roman numerals and hour markers surrounded by a polished silver-tone bezel.<br><br>Size: 6.75\" H (17 cm) x 6.25\" W (16 cm)"},
      "Appalachian Sherpa blanket": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/blanket-thumb.jpg","description":"This high-end plush blanket has <em>30 Years</em> embroidered on the corner. It’s made of faux suede on one side and soft Sherpa fleece on the other.<br><br>Size:  50\" H x 60\" L"},
      "Epiphany III framed Art Print": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2019/0213/30yearprint-epiphany-sm.jpg","description":"This stunning photograph by B.C. artist Marvin Pelkey is printed on fine art paper and comes matted in a black frame. The frame has <em>In recognition of thirty years of service</em> engraved on a plaque."},
      "Sterling silver earrings": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0208/silverearringsthumb.jpg","description":"These sterling silver drop earrings are individually handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. They come in a box with <em>In recognition of thirty years of service</em> engraved on the top.<br>Note: These earrings are designed to coordinate with the 35 year sterling silver bracelet."},
      "$150.00 PECSF charitable donation": {"URI":"/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
      "Forest Cove framed art print": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2019/0213/40yearprint-forestcove-sm.jpg", "description": "This colourful landscape print was originally painted by artist Michaela Davidson, from Lake Cowichan, B.C. The artwork is presented in a matted green frame with <em>In recognition of forty years of service</em> engraved on a plaque."},
      "Bushnell Prime binoculars": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2019/0213/35yearbinoculars-sm.png","description":"The Bushnell® Prime 8x42 binocular is the perfect blend of magnification and field of view, allowing easy viewing of moving animals and birds.  The EXO barrier and fully multi coated optics deliver bright images in any weather conditions. The Prime binoculars feature Bushnell’s newest and best protective lens coating that molecularly bonds to the glass, repelling water, oil, dust, debris and preventing scratches. With IPX7 waterproof construction, O-ring sealed optics stay dry inside, when immersed in three feet of water for up to 30 minutes. They come with a soft case. Note: Due to the nature of this award, engraving is not possible.<br />Configuration = 8 x 42mm<br />Field of View 350/117 (ft.@1000 yrds/m@1000m)<br />Close Focus = 10F/3M<br />Weight = 23.3 oz (660 gm)"},
      "Blue flower bouquet glass vase": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/vase-thumb.jpg","description":"Each of these unique glass vases are hand-blown by B.C. artist Robert Held in Parksville. <br>Size: 11.5\" H<br>Note: Due to the nature of this award, engraving is not possible."},
      "Women's Gold Watch with Black Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Gold Watch with Brown Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Gold Watch with Gold Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Silver Watch with Silver Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Silver Watch with Two-toned Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Silver Watch with Black Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Women's Silver Watch with Brown Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Gold Watch with Black Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Gold Watch with Brown Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Gold Watch with Gold Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Silver Watch with Silver Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Silver Watch with Two-toned Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Silver Watch with Black Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Men's Silver Watch with Brown Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/Watches-group-thumb.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
      "Sterling Silver Bracelet - size A": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg","description":"This sterling silver bracelet has a 14 kt yellow gold insert. It is handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. It comes in a box with In recognition of thirty five years of service engraved on the top.<br>Size:<br>Cuff is ¾ inch wide and comes in two sizes: <br>Size A fits 6 ½\" - 7 ½\" wrist<br>Size B fits 7 ½\" -  8 ½\" wrist"},
      "Sterling Silver Bracelet - size B": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg","description":"This sterling silver bracelet has a 14 kt yellow gold insert. It is handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. It comes in a box with In recognition of thirty five years of service engraved on the top.<br>Size:<br>Cuff is ¾ inch wide and comes in two sizes: <br>Size A fits 6 ½\" - 7 ½\" wrist<br>Size B fits 7 ½\" -  8 ½\" wrist"},
      "$300.00 PECSF charitable donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
      //"Choice TBC": {"URI": "","":""},
      "Napolean Beauty ergo mantle clock": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/napoleonclock-thumb.jpg","description":"This clock features a wood frame in solids and veneers in a warm oak finish with burl accents. It has <em>In recognition of forty years of service</em> engraved on front plate. A brass finish bezel surrounds the dial. It has rich chimes which you can adjust to your preference (quarterly Westminster, quarterly Ava Maria, hourly Westminster or hourly/half hour strike).<br>Size: 20\" x 10\""},
      "Genuine diamond pendant and chain": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0213/diamondnecklace-thumb.png","description":"This necklace features a 10 kt white gold, four claw pendant and 18 inch Box chain. The round brilliant cut diamonds are .20-carat total weight. It comes in a box <em>In recognition of forty years of service</em> engraved on the top."},
      "Blue Flower Bouquet glass bowl": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bowl40yearcopy-thumb.jpg","description":"Each of these unique glass bowls is hand-blown by B.C. artist Robert Held in Parksville. <br>Size: 7\" H<br>Note: Due to the nature of this award, engraving is not possible."},
      "Genuine diamond stud earrings": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2019/0228/diamondearrings2.jpg","description":"This necklace features a 10 kt white gold, four claw pendant and 18 inch Box chain. The round brilliant cut diamonds are .20-carat total weight. It comes in a box <em>In recognition of forty years of service</em> engraved on the top."},
      //"Michaela Davidson Print - Sunbreakers",{"URI": "","":""},
      "$400.00 PECSF charitable donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
      //"Choice TBC","":""},
      "$450.00 PECSF charitable donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
      //"Choice TBC": {"URI":"". "description":""},
      "$500.00 PECSF charitable donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."}
      //"Award already Sent": {"URI":"","description":""},
    };
  return giftImages;
  }
