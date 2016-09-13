<h2 style="margin-top: 15px;" align="center">Thanks for voting!</h2>
<div class="resultswrap">
<h3 class="compare">Compare your choices with those of the rest of the BC Public Service</h3>

<?php
// good copy jun 23 4pm

if(!defined('INCLUDE_CHECK')) die('You are not allowed to execute this file directly');

$current_user_id="";
if(isset($_SERVER['HTTP_SM_USER'])){
   $current_user_id = str_replace("idir\\", "", strtolower($_SERVER['HTTP_SM_USER']));
}

$pagereturn = mysql_query("SELECT * FROM sort_pages");

while($page=mysql_fetch_assoc($pagereturn)){
    
	echo '<div style="clear: both;"></div><div class="resultsdots'.$page['id'].'">'; 
	echo '
	............................................................................................................................................................................
	
	</div><!-- clear formating now --><div style="clear: both;"></div>
	<h2 class="description_result">'.$page['title'].'</h2>';
	echo '<div><h2 class="question_result">'.$page['description'].'</h2></div>';
    
       $userres = mysql_query('SELECT  o.title as title, o.url as url, o.short as short FROM sort_objects o JOIN sort_inputs i on i.qid=o.id WHERE i.idir="'.mysql_real_escape_string($current_user_id).'" AND i.pid='.$page['id'].' ORDER BY i.id');
           
       $userbars=array();
       echo '
	   <!-- make a simple list for display only, ornamental.  -->
	   <ul class="thenumbers numbers_left"><li>1</li><li>2</li><li>3</li><li>4</li><li>5</li><li>6</li></ul>
	   <div class="chart userchoice"><h3>Your response:</h3>';
    
       while($userresrow=mysql_fetch_assoc($userres))
	{
		$userbars[]=$userresrow;	
		// Storing the max vote, so we can scale the bars of the chart:
	}



	


	$userbarstr='';

	// The colors of the bars SINGLE USER CHOICE: (used to be: '#ff9900','#66cc00','#3399cc','#dd0000','#800080','#ffee44')
	$colors=array('#ff9900','#66cc00','#3399cc','#dd0000','#800080','#ffee44');

	foreach($userbars as $k=>$v)
	{
		// Buildling the bar string:
		$userbarstr.='
		<div class="bar" style="border: 1px solid '.$colors[$k].';">
			'.$v['title'].'	
		</div>';
	}
       echo $userbarstr;
   
       echo '</div>';

       // If the poll has been submitted:

       //	Selecting the sample tutorials and ordering 
       //	them by the votes each of them received:
       $res = mysql_query("SELECT * FROM sort_objects WHERE pid=".$page['id']." ORDER BY votes DESC");

       $maxVote=0;
       $bars=array();
  
       echo '
	   <ul class="thenumbers numbers_right"><li>1</li><li>2</li><li>3</li><li>4</li><li>5</li><li>6</li></ul><!-- make a simple list for display -->
	   <div class="chart systemchoice"><h3>BCPS-wide ranking to date:</h3>';  
       while($row=mysql_fetch_assoc($res))
	{
		$bars[]=$row;	
		// Storing the max vote, so we can scale the bars of the chart:
		if($row['votes']>$maxVote) $maxVote = $row['votes'];
	}






	
	$barstr='';

	// The colors of the bars EVERYONE:
	$colors=array('#ff9900','#66cc00','#3399cc','#dd0000','#800080','#ffee44');

	foreach($bars as $k=>$v)
	{
		/* Buildling the bar string: --- we use this code to style the widths also (to make a bar graph). currently not needed: style="width:'.max((int)(($v['votes']/$maxVote)*290),100).'px; border: 1px solid '.$colors[$k].';" */
		$barstr.='
		<div class="bar" style="border: 1px solid '.$colors[$k].';">
			'.$v['title'].'	
		</div>';
	}
       echo $barstr;
       
       // The total number of votes cast in the poll:
	list($totVotes) = mysql_fetch_array(mysql_query("SELECT COUNT(*) FROM sort_votes where pid=".$page['id']));

       echo '<div class="tot-votes">Total '.$totVotes.' votes</div>';    
       echo '</div>';
	

}

?>

</div><!-- close resultswrap -->

</div>

