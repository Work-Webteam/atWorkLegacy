<?php

// Hiding notices:
error_reporting(E_ALL^E_NOTICE);

// Including file for the DB connection:
define("INCLUDE_CHECK",1);
require 'connect.php';

if($_POST['sortdata'] && isset($_SERVER['HTTP_SM_USER']) && is_numeric($_POST['submitpid']))
{      
       $current_user_id = str_replace("idir\\", "", strtolower($_SERVER['HTTP_SM_USER']));

	// The data arrives as a comma-separated string,
	// so we extract each post ids:
	$data=explode(',',str_replace('li','',$_POST['sortdata']));

	// Getting the number of objects
	list($tot_objects) = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM sort_objects WHERE pid=".$_POST['submitpid']));

	if(count($data)!=$tot_objects) die("Wrong data!");

	foreach($data as $k=>$v)
	{
		// Building the sql query:
		$str[]='('.(int)$v.','.($tot_objects-$k).')';
	}
	$str = 'VALUES'.join(',',$str);
	

       // create array to insert like (idir, qid, input, other)
       $idarrays=explode('`,`',$_POST['userinputids']);
       $inputsarrays=explode('|||||',$_POST['userinputs']);
       
       $len = sizeof($idarrays);
       for($counter=0;$counter<$len;$counter++){
         if ($idarrays[$counter]==$_POST['otherqid']){
                $userinputs[$counter]='("'.mysql_real_escape_string($current_user_id).'",'.$_POST['submitpid'].','.$idarrays[$counter].',"'.mysql_real_escape_string($inputsarrays[$counter]).'","'.mysql_real_escape_string($_POST['othertitle']).'")';
         }else{
                $userinputs[$counter]='("'.mysql_real_escape_string($current_user_id).'",'.$_POST['submitpid'].','.$idarrays[$counter].',"'.mysql_real_escape_string($inputsarrays[$counter]).'", NULL)';
         }
       }
       $userinputs = 'VALUES'.join(',',$userinputs);
	
       // This will limit voting to one idir life time:
	mysql_query("	INSERT INTO `sort_votes` (idir,pid,date_submit,dt_submit)
					VALUES ('".mysql_real_escape_string($current_user_id)."',".$_POST['submitpid'].",NOW(),NOW())");

	//	If the user has not voted yet:
	if(mysql_affected_rows($link)==1)
	{
		mysql_query('	INSERT INTO `sort_objects` (id,votes) '.$str.'
						ON DUPLICATE KEY UPDATE votes = votes+VALUES(votes)');
              mysql_query (' INSERT INTO `sort_inputs` (idir,pid,qid,input,title) '.$userinputs);
	}
}


$votedpid = 0;
if(isset($_SERVER['HTTP_SM_USER'])){
  $current_user_id = str_replace("idir\\", "", strtolower($_SERVER['HTTP_SM_USER']));
  $presult=mysql_query("	SELECT MAX(pid) as pid FROM sort_votes
						WHERE idir='".mysql_real_escape_string($current_user_id)."'");
  $obj= mysql_fetch_object($presult);  
  if (is_numeric($obj->pid)) $votedpid = $obj->pid; 
}

$currentpid = $votedpid+1;

?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>PSI Drop and Drag Vote/Ranking Interface</title>
<link href="//fonts.googleapis.com/css?family=Muli" rel="stylesheet" type="text/css" />
<link rel="stylesheet" type="text/css" href="viscon.css" />
<!--[if IE 7]>
<link rel="stylesheet" type="text/css" href="ie7.css" />
<![endif]-->
<script type="text/javascript" src="/sites/all/modules/jquery_ui/jquery.ui/jquery-1.2.6.js"></script>
<script type="text/javascript" src="/sites/all/modules/jquery_ui/jquery.ui/ui/jquery.ui.all.js"></script>
<script type="text/javascript" src="script.js"></script>
<script type="text/javascript" src="maxlength.js"></script>
<script type="text/javascript" src="placeheld.js"></script>
<script type="text/javascript">
$(document).ready(function(){

	// show more toggle for more comments
	$(".slidingDiv").hide();
	$(".show_hide").show();
	$(".show_hide").click(function(e){ $("#sliding".concat(this.id)).slideToggle();	});
	
	// fades and annimations for rollever peices -- but guess what..? doesn't always work in IE so commenting out for now
	$(".tut").hover(function() { $(this).animate({ backgroundColor: "#eee" }, "fast"); },
    function() { $(this).animate({ backgroundColor: "#fff" }, "fast"); } );
       
       // enable button only after document ready
       $("#submitPoll").removeAttr('disabled');

       $( '.usercomments').placeHeld();
       $('#othertitleinput').placeHeld();
	
});
</script>
</head>

<body class="page-<?php echo $currentpid ?>">

<div id="wrapper">
	
<?php
echo "<img class=\"instructions_icon\" src=\"img/instructions_icon.png\" /><div class=\"instructions\"><p>Please rank the following concepts according to their importance to you by dragging and dropping the terms into position in the list. When complete, select <b>Save & Go To Next Step.</b></p></div>
	
	<div id=\"navbg\">........................................................................................................................</div>
	
	<div class=\"navimages\">";
	switch($currentpid){
		case 1:
		echo	"<img class=\"navimage\" src=\"img/progress1_over.png\" /><img class=\"navimage\" src=\"img/progress2.png\" /><img class=\"navimage\" src=\"img/progress3.png\" /><img class=\"navimage\" src=\"img/progress4.png\" />";
		break;
		case 2:
		echo	"<img class=\"navimage\" src=\"img/progress1.png\" /><img class=\"navimage\" src=\"img/progress2_over.png\" /><img class=\"navimage\" src=\"img/progress3.png\" /><img class=\"navimage\" src=\"img/progress4.png\" />";
		break;
		case 3:
		echo	"<img class=\"navimage\" src=\"img/progress1.png\" /><img class=\"navimage\" src=\"img/progress2.png\" /><img class=\"navimage\" src=\"img/progress3_over.png\" /><img class=\"navimage\" src=\"img/progress4.png\" />";
		break;
		default:
		echo	"<img class=\"navimage\" src=\"img/progress1.png\" /><img class=\"navimage\" src=\"img/progress2.png\" /><img class=\"navimage\" src=\"img/progress3.png\" /><img class=\"navimage\" src=\"img/progress4_over.png\" />";
		break;
	}

	echo "</div>";	
	switch($currentpid) {
		case 1:
		echo "
	<div class=\"navdesc\"><span style=\"color: #feb913;\">Employee Experience</span><span>Service Experience</span><span>Operational Experience</span><span>Review</span></div>";
		break;
		
		case 2:
		echo "
	<div class=\"navdesc\"><span>Employee Experience</span><span style=\"color: #feb913;\">Service Experience</span><span>Operational Experience</span><span>Review</span></div>";
		break;
		
		case 3:
		echo "
	<div class=\"navdesc\"><span>Employee Experience</span><span>Service Experience</span><span style=\"color: #feb913;\">Operational Experience</span><span>Review</span></div>";
		break;
		
		default:
		echo "
	<div class=\"navdesc\"><span>Employee Experience</span><span>Service Experience</span><span>Operational Experience</span><span style=\"color: #feb913;\">Review</span></div>";
		break;
	}

// If we are not on the data.php?results page:
if($currentpid <= 3 && !array_key_exists('results',$_GET) && isset($_SERVER['HTTP_SM_USER']))
{      
    $respagetitlerow = mysql_fetch_row(mysql_query("SELECT title, description FROM sort_pages WHERE id=".$currentpid));
    
	
	

	echo "
	<div id=\"mainquestion\">
	
	<img class=\"neaticon\" src=\"img/Q".$currentpid."_employee_icon.png\" />	
	
	";

	echo '<h2 class="question">'.$respagetitlerow[0].'</h2>';
	echo '<h2 class="description">'.$respagetitlerow[1].'</h2>';
	echo "<div style=\"clear: both;\"></div>";
	// below commented out for now as per KW, june 2011
	// echo '<h3 class="concepthead">Concepts:</h3>';

	echo '<ul class="sort">';

	// Showing the tutorials by random
	$res = mysql_query("SELECT * FROM sort_objects WHERE pid=".$currentpid." AND other=0 UNION SELECT * FROM sort_objects WHERE pid=".$currentpid." AND other=1 ORDER BY other, RAND()");

    $rnum = 1;
	while($row=mysql_fetch_assoc($res))
	{?>




    <li id="li<?php echo $row['id']?>">
		<div class="tut">
		<div class="showhide"><a href="#" id="Div<?php echo $row['id']?>" class="show_hide">Provide additional comments:</a></div>            
          <div class="rnumber"><?php echo $rnum;?></div>
            <div class="title">  
              <?php if( $row['other']  == chr(0x01) ):?>
                  <!-- "other" title -->
                  <!-- my own idea: --><input type="text" placeholder="[optional] enter your concept here" name="other<?php echo $row['id'] ?>" id="othertitleinput" maxlength="100" size="50" />
              <?php else:?>
                  <?php echo $row['title']?>
              <?php endif;?>            	
            </div>
          	<div id="slidingDiv<?php echo $row['id']?>" class="slidingDiv">
            <textarea placeholder="Comment on this concept..." class="usercomments" id="<?php echo $row['id']?>" data-maxsize="280" data-output="status<?php echo $row['id']?>"></textarea>
            <div class="letter_counter">Character count: <div class="lettercount" id="status<?php echo $row['id']?>"></div><span style="font-size: 11px;">/280</span></div>
            </div>
      	</div><!-- closes tut -->
</li>
	<?php $rnum=$rnum+1; }	?>
</ul>

  
<!-- button!!! -->
	<div class="button-holder"><span style="color: red; text-align: right; font-size: 12px;">*Once you click this button, you cannot change your answers. </span>
    	<?php if($currentpid == 3):?><a href="" id="submitPoll" class="button" disabled="disabled"><img src="img/nextbutton.png" /></a>
		<?php else:?><a href="" id="submitPoll" class="button" disabled="disabled"><img src="img/nextbutton.png" /></a><?php endif;?>
    </div>	
</div><!-- close the mainquestionwrap --> 
</div><!-- close the wrapper -->
  
<?php
}
else require "results.php";
// The above require saves us from having to style another separate page. Jonathan Bell likes this.

?>


<!-- The form below is not directly available to the user -->

<form action="" id="sform" method="post">
<input name="sortdata" id="sortdata" type="hidden" value="" />
<input name="submitpid" id="submitpid" type="hidden" value="<?php echo $currentpid; ?>" />
<input name="userinputids" id="userinputids" type="hidden" value="" />
<input name="userinputs" id="userinputs" type="hidden" value="" />
<input name="othertitle" id="othertitle" type="hidden" value="" />
<input name="otherqid" id="otherqid" type="hidden" value="" />
</form>



</body>
</html>
