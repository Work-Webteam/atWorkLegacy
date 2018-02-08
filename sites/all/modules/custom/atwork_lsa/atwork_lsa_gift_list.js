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
  
  /* TODO: Insert image URI's */
  function giftListImages() {
  giftImages = {
  	//"2016 Recipient - award received": ,
  	//"CChoice TBC": ,
  	"Framed Certificate and Cross 'Starry Blue' Ballpoint Pen": 	"/sites/default/files/lsa_2015/25_ballpoint-pen-final.jpg",
  	"Cross 'Starry Blue' Ballpoint Pen - No Certificate":				"/sites/default/files/lsa_2015/25_ballpoint-pen-final.jpg",
  	//"Framed Certificate and Leather Tablet Holder with Notepad": , // TODO: Replace with image URI once available
  	//"Leather Tablet Holder with Notepad - No Certificate": , // TODO: Replace with image URI once available
  	"Framed Certificate and Sterling Silver White Pearl Earrings": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg",
  	"Sterling Silver White Pearl Earrings - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/pearl-earrings-thumb.jpg",
  	"Framed Certificate and Leather Passport and Luggage Tag Set": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg",
  	"Leather Passport and Luggage Tag Set - No Certificate": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/passport-luggage-thumb.jpg",
  	"$75.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Choice TBC",
  	"Colonnade Clock": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/clock-thumb.jpg",
  	"Appalachian Sherpa Blanket": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/blanket-thumb.jpg",
  	//"Roy Vickers Print - Tofino Sunrise",
  	"Solid Sterling Drop Earrings": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/silver-earrings-thumb.jpg",
  	"$150.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Choice TBC",
  	"Bushnell Compact Binoculars": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bushnell-thumb.jpg",
  	"Hand-Blown Glass Vase by Robert Held": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/vase-thumb.jpg",
  	"Ladies' Gold Watch with Black Strap": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/watches-thumb.jpg",
  	"Ladies' Gold Watch with Brown Strap": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg",
  	"Ladies' Gold Watch with Gold Strap": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg",
  	"Ladies' Silver Watch with Silver Face": "/sites/default/files/bg/image/2015/0224/35watchsilverwtb.jpg",
  	"Ladies' Silver Watch with Two-toned Face": "/sites/default/files/lsa_2015/35_watch_silver_gold.png",
  	"Men's Gold Watch with Black Strap": "/sites/default/files/bg/image/2015/0224/35watchleathertb.jpg",
  	"Men's Gold Watch with Brown Strap": "/sites/default/files/bg/image/2015/0224/35watchleathertb.jpg",
  	"Men's Gold Watch with Gold Strap": "/sites/default/files/bg/image/2015/0224/35watchgoldtb.jpg",
  	"Men's Silver Watch with Silver Face": "/sites/default/files/bg/image/2015/0224/35watchsilverwtb.jpg",
  	"Men's Silver Watch with Two-toned Face": "/sites/default/files/lsa_2015/35_watch_silver_gold.png",
  	"Sterling Silver Bracelet - size A": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg",
  	"Sterling Silver Bracelet - size B": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bracelet-1-thumb.jpg",
  	"$300.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Choice TBC",
  	"Napolean Beauty Ergo Mantle Clock": "/sites/default/files/lsa_2015/40_clock_2016.jpg",
  	"14kt White Gold Diamond Stud Earrings": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/diamondearrings-thumb.jpg",
  	"Hand-Blown Glass Bowl by Robert Held": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/bowl40yearcopy-thumb.jpg",
  	//"Michaela Davidson Print - Sunbreakers",
  	"10kt White Gold Diamond Pendant and Chain": "/sites/default/files/styles/node_image/public/bg/image/2018/0201/diamondnecklace-thumb.jpg",
  	"$400.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Choice TBC",
  	"$450.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Choice TBC",
  	"$500.00 PECSF Charitible Donation": "/sites/default/files/lsa_2015/25_pecsf.jpg",
  	//"Award already Sent",
  };
  return giftImages;
  }
 