/**
 * JS function for LSA Gift and key array
 * Drupal.jquery
 * Written by Thayne Werdal Feb 2016
 */

  function gift_list_complete() {
    gift_list = {
	    1: "2016 Recipient - award received",
	    2: "25 - Choice TBC",
	    3: "25 - Framed Certificate and Cross 'Starry Blue' Ballpoint Pen",
	    4: "25 - Cross 'Starry Blue' Ballpoint Pen - No Certificate",
		  5: "25 - Framed Certificate and Leather Tablet Holder with Notepad",
		  6: "25 - Leather Tablet Holder with Notepad - No Certificate",
		  7: "25 - Framed Certificate and Sterling Silver White Pearl Earrings",
		  8: "25 - Sterling Silver White Pearl Earrings - No Certificate",
		  9: "25 - Framed Certificate and Leather Passport and Luggage Tag Set",
		  10: "25 - Leather Passport and Luggage Tag Set - No Certificate",
		  11: "25 - $75.00 PECSF Charitible Donation",
		  12: "30 - Choice TBC",
		  13: "30 - Colonnade Clock",
		  14: "30 - Appalachian Sherpa Blanket",
		  15: "30 - Roy Vickers Print - Tofino Sunrise",
		  16: "30 - Solid Sterling Drop Earrings",
		  17: "30 - $150.00 PECSF Charitible Donation",
		  18: "35 - Choice TBC",
		  19: "35 - Bushnell Compact Binoculars",
		  20: "35 - Hand-Blown Glass Vase by Robert Held",
		  21: "35 - Ladies' Gold Watch with Black Strap",
		  22: "35 - Ladies' Gold Watch with Brown Strap",
		  23: "35 - Ladies' Gold Watch with Gold Strap",
		  24: "35 - Ladies' Silver Watch with Silver Face",
		  25: "35 - Ladies' Silver Watch with Two-toned Face",
		  26: "35 - Men's Gold Watch with Black Strap",
		  27: "35 - Men's Gold Watch with Brown Strap",
		  28: "35 - Men's Gold Watch with Gold Strap",
		  29: "35 - Men's Silver Watch with Silver Face",
		  30: "35 - Men's Silver Watch with Two-toned Face",
		  31: "35 - Sterling Silver Bracelet - size A",
		  32: "35 - Sterling Silver Bracelet - size B",
		  33: "35 - $300.00 PECSF Charitible Donation",
		  34: "40 - Choice TBC",
		  35: "40 - Napolean Beauty Ergo Mantle Clock",
		  36: "40 - 14kt White Gold Diamond Stud Earrings",
		  37: "40 - Hand-Blown Glass Bowl by Robert Held",
		  38: "40 - Michaela Davidson Print - Sunbreakers",
		  39: "40 - 10kt White Gold Diamond Pendant and Chain",
		  40: "40 - $400.00 PECSF Charitible Donation",
		  41: "45 - Choice TBC",
		  42: "45 - $450.00 PECSF Charitible Donation",
		  43: "50 - Choice TBC",
		  44: "50 - $500.00 PECSF Charitible Donation",
		  45: "Award already Sent",
    };
    return gift_list;
  }
  
  function giftListImages() {
  giftImages = {
  	//"2016 Recipient - award received": ,
  	//"Choice TBC": ,
  	"Framed Certificate and Cross 'Starry Blue' Ballpoint Pen": 	{ "URI": "/sites/default/files/lsa_2015/25_ballpoint-pen-final.jpg", "description":"This Cross® Calais chrome and blue lacquer rollerball pen is lightweight with a bold profile. It comes in a box with 25 Years engraved on the lid."},
  	//"Framed Certificate and Leather Tablet Holder with Notepad": , // { "URI": "", "description":"This tablet holder is made with durable performance herringbone twill with genuine leather accents. It has 25 Years debossed on the front.<br>Adjustable brackets hold most tablet models including all versions of the iPad and iPad Air. It includes a magnetic closure strap, business card pockets, an elastic pen loop, a 6.75\" x 9.5\" writing pad and a screen cleaner that fits behind tablet. Tablet is not included.<br>Size: 10.5\" H X 1\" W x 8.75\" D"},
  	"Framed Certificate and Leather Passport and Luggage Tag Set": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg","description":"This genuine black leather passport holder and luggage tag has 25 Years debossed on the front. It has a magnetic closure."},
  	//"Leather Passport and Luggage Tag Set - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg",
  	"Framed Certificate and Sterling Silver White Pearl Earrings": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg", "description":"These sterling silver, fresh water pearl earrings have an accent of gold. They are made in Vancouver, B.C. by Howling Dog Artisan Jewellery.<br>Note: Due to the nature of this award, engraving is not possible."},
  	//"Sterling Silver White Pearl Earrings - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg",
  	"$75.00 PECSF Charitible Donation": {"URI":"/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
  	//"Choice TBC",
  	"Colonnade Clock": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/clock-thumb.jpg","description":"This bold optical crystal, carriage-style clock has In recognition of thirty years of service engraved on front plate. It features a black glass center panel and a white dial with black Roman numerals and hour markers surrounded by a polished silver-tone bezel.<br><br>Size: 6.75\" H (17 cm) x 6.25\" W (16 cm)"},
  	"Appalachian Sherpa Blanket": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/blanket-thumb.jpg","description":"This high-end plush blanket has <em>30 Years</em> embroidered on the corner. It’s made of faux suede on one side and soft Sherpa fleece on the other.<br><br>Size:  50\" H x 60\" L"},
  	//"Roy Vickers Print - Tofino Sunrise": {"URI":"","description":""},
  	"Solid Sterling Drop Earrings": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/silver-earrings-thumb.jpg","description":"These sterling silver drop earrings are individually handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. They come in a box with <em>In recognition of thirty years of service</em> engraved on the top.<br>Note: These earrings are designed to coordinate with the 35 year sterling silver bracelet."},
  	"$150.00 PECSF Charitible Donation": {"URI":"/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
  	//"Choice TBC","":""},
  	"Bushnell Compact Binoculars": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/bushnell-thumb.jpg","description":"These binoculars feature outstanding optical performance in a trim, balanced roof-prism design. They have a textured center-focus knob for easy, precise adjustments; BaK-4 roof prisms for bright, clear, crisp viewing; and fully multi-coated optics for superior light transmission and brightness. The non-slip rubber armor absorbs shock and they are fully waterproof and fogproof. They come with a soft case.<br>Magnification x Objective Lens = 8 x 42mm<br>Field of View 393/131 (ft.@1000 yrds/m@1000m)<br>Weight = 23.1 oz (654 gm) <br>Note: Due to the nature of this award, engraving is not possible."},
  	"Hand-Blown Glass Vase by Robert Held": {"URI":"/sites/default/files/styles/node_image/public/bg/image/2018/0201/vase-thumb.jpg","description":"Each of these unique glass vases are hand-blown by B.C. artist Robert Held in Parksville. <br>Size: 11.5\" H<br>Note: Due to the nature of this award, engraving is not possible."},
  	"Ladies' Gold Watch with Black Strap": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/watches-thumb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Ladies' Gold Watch with Brown Strap": {"URI": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Ladies' Gold Watch with Gold Strap": {"URI": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Ladies' Silver Watch with Silver Face": {"URI": "/sites/default/files/bg/image/2015/0224/35watchsilverwtb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Ladies' Silver Watch with Two-toned Face": {"URI": "/sites/default/files/lsa_2015/35_watch_silver_gold.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Men's Gold Watch with Black Strap": {"URI": "/sites/default/files/bg/image/2015/0224/35watchleathertb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Men's Gold Watch with Brown Strap": {"URI": "/sites/default/files/bg/image/2015/0224/35watchleathertb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Men's Gold Watch with Gold Strap": {"URI": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Men's Silver Watch with Silver Face": {"URI": "/sites/default/files/bg/image/2015/0224/35watchsilverwtb.jpg","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Men's Silver Watch with Two-toned Face": {"URI": "/sites/default/files/lsa_2015/35_watch_silver_gold.png","description":"This watch features the BC Coat of Arms on the dial and your name and <em>35 Years</em> is engraved on the back of the watch face. It comes in a choice of gold, silver or two-toned watch face with a plated strap, or a black or brown leather strap. <br>Size: <br>Larger watch face (men’s) = 38 mm W<br>Strap width: approx. 20 mm<br>Smaller watch face (women’s) = 29 mm W<br>Strap width: approx. 14 mm"},
  	"Sterling Silver Bracelet - size A": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg","description":"This sterling silver bracelet has a 14 kt yellow gold insert. It is handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. It comes in a box with In recognition of thirty five years of service engraved on the top.<br>Size:<br>Cuff is ¾ inch wide and comes in two sizes: <br>Size A fits 6 ½\" - 7 ½\" wrist<br>Size B fits 7 ½\" -  8 ½\" wrist"},
  	"Sterling Silver Bracelet - size B": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg","description":"This sterling silver bracelet has a 14 kt yellow gold insert. It is handcrafted by B.C. artists Nancy Dawson and Vincent Henson of Silver Eagles Design Studio in Alert Bay. It comes in a box with In recognition of thirty five years of service engraved on the top.<br>Size:<br>Cuff is ¾ inch wide and comes in two sizes: <br>Size A fits 6 ½\" - 7 ½\" wrist<br>Size B fits 7 ½\" -  8 ½\" wrist"},
  	"$300.00 PECSF Charitible Donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
  	//"Choice TBC": {"URI": "","":""},
  	"Napolean Beauty Ergo Mantle Clock": {"URI": "/sites/default/files/lsa_2015/40_clock_2016.jpg","description":"This clock features a wood frame in solids and veneers in a warm oak finish with burl accents. It has <em>In recognition of forty years of service</em> engraved on front plate. A brass finish bezel surrounds the dial. It has rich chimes which you can adjust to your preference (quarterly Westminster, quarterly Ava Maria, hourly Westminster or hourly/half hour strike).<br>Size: 20\" x 10\""},
  	"10kt White Gold Diamond Pendant and Chain": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/diamondnecklace-thumb.jpg","description":"This necklace features a 10 kt white gold, four claw pendant and 18 inch Box chain. The round brilliant cut diamonds are .20-carat total weight. It comes in a box <em>In recognition of forty years of service</em> engraved on the top."},
  	"Hand-Blown Glass Bowl by Robert Held": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bowl40yearcopy-thumb.jpg","description":"Each of these unique glass bowls is hand-blown by B.C. artist Robert Held in Parksville. <br>Size: 7\" H<br>Note: Due to the nature of this award, engraving is not possible."},
  	"14kt White Gold Diamond Stud Earrings": {"URI": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/diamondearrings-thumb.jpg","description":"This necklace features a 10 kt white gold, four claw pendant and 18 inch Box chain. The round brilliant cut diamonds are .20-carat total weight. It comes in a box <em>In recognition of forty years of service</em> engraved on the top."},
  	//"Michaela Davidson Print - Sunbreakers",{"URI": "","":""},
  	"$400.00 PECSF Charitible Donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
  	//"Choice TBC","":""},
  	"$450.00 PECSF Charitible Donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."},
  	//"Choice TBC": {"URI":"". "description":""},
  	"$500.00 PECSF Charitible Donation": {"URI": "/sites/default/files/lsa_2015/25_pecsf.jpg","desciption":"Instead of choosing an award from the catalogue, you can opt to make a charitable donation via the Provincial Employees Community Services Fund. A framed certificate of service, signed by the Premier of British Columbia, will be presented to you noting your charitable contribution.<br>You can donate to the fund supported pool of charities in your region, or you can choose one or two specific charities to receive your donation.<br>Note: Charitable tax receipts are not issued for Long Service Award donations."}
  	//"Award already Sent": {"URI":"","description":""},
  };
  return giftImages;
  }
 