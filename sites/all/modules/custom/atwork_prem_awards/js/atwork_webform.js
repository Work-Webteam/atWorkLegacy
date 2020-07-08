(function ($) {
    $('input').click(function() {
      let userSelected = this.id;
      let unselected = getUnselectedByColumn(userSelected.slice(-3,-2)); 
      deselectColumn(userSelected,unselected);
    });
})(jQuery);


/*
  function getUnselectedByColumn determines which rows in the chosen column
  need to be deselcted.
 */
function getUnselectedByColumn(selected) {
  var unselected = []; 
  switch(selected) {
    case '1':
      unselected.push('2','3');
    	break;
    case '2':
    	unselected.push('1','3');
    	break;
    case '3':
    	unselected.push('1','2');
    	break;
    default:
    	break;
  }
  return unselected;
}


/*
  function deselectColumn takes selected and non-selected options 
  and ensures that choice cant be selected more that once per column
 */
function deselectColumn(idSelected, unselected) {
  var i;
  for(i = 0; i < unselected.length; i++){
  	let targetID = idSelected.slice(0,-3) + unselected[i] + '-' + 
  	  idSelected.slice(-1);
    document.getElementById(targetID).checked = false;
  };
}