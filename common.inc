<?php
ini_set('display_errors', true);
error_reporting(1);
define ("HOST","localhost");
// fill in correct name of database
define ("DBNAME","sal");
// fill in correct loginname/password
define ("ADMIN","root");
define ("WWOORD","root");

//For this simple experiment we read all common parameters we will ever need.
$table_name="hit_commonparameters";
$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);

if (mysqli_connect_errno()) {
    printf("Connect failed");
    exit();
}

$sql="SELECT * FROM $table_name";

if (!$result=mysqli_query($connection, $sql)) {
    printf("Cannot execute SELECT FROM $table_name");
}

while ($row=mysqli_fetch_array($result)) {
	$name=$row['name'];	
	$value=$row['value'];
	$$name=$value;
}

//reads one common parameter
//example: $startexperiment=readCommonParameter("startexperiment");
function readCommonParameter($name){
	$table_name="hit_commonparameters";
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="SELECT * FROM $table_name WHERE (name='$name')";
	$result=mysqli_query($connection, $sql);
	if ($row=mysqli_fetch_array($result)) {
		$value=$row['value'];
	}
	RETURN $value;
}

//Lookups one variable in one specif record
//example: $role=lookUp("groupcomposition","pp='$ppnummer'","role");
function lookUp($table_name,$condition,$name){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);

    if (mysqli_connect_errno()) {
        printf("Connect failed");
        exit();
    }

	if ($condition=="") {
            $sql="SELECT $name FROM $table_name";
	} else {
	    $sql="SELECT $name FROM $table_name WHERE ($condition)";
    }

    if(!$result=mysqli_query($connection, $sql)) {
        printf("Cannot execute $sql");
    }

	if ($row=mysqli_fetch_array($result)) {
		$value=$row[$name];
	}
	else $value="";

	RETURN $value;
}

//Concates value to already existing variable, else stores the value
//example concatValueOne("ppnummers","ppnummer=$ppnummer and session=$session","ToM","suspicious");
function concatValueOne($table_name,$condition,$name,$value){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="UPDATE $table_name SET $name=CONCAT($name,\"$value\") WHERE ($condition)";
	$result=mysqli_query($connection, $sql);
}

//Updates one variable in one record
//example updateTableOne("ppnummers","ppnummer=$ppnummer and session=$session","period","1");
function updateTableOne($table_name,$condition,$name,$value){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
    if (mysqli_connect_errno()) {
        printf("Connect failed");
        exit();
    }
    $sql="UPDATE $table_name SET $name=\"$value\" WHERE ($condition)";
	$result=mysqli_query($connection, $sql);// or die("Couldn't execute query ".$sql);
}

//Adds a number to one variable in one record
//example updateTableOne("ppnummers","ppnummer=$ppnummer and session=$session","period","1");
function updateTableOneAdd($table_name,$condition,$name,$value){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="UPDATE $table_name SET $name=$name+\"$value\" WHERE ($condition)";
	$result=mysqli_query($connection, $sql);
}

//Updates more variables in the same record
//example: updateTableMore("glazen","codeglas=\"$codeglas\"","hoogte=\"$hoogte\", jeneverofniet=\"$jeneverofniet\"");
function updateTableMore($table_name,$condition,$updatestring){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="UPDATE $table_name SET ".$updatestring." WHERE ($condition)";
	$result=mysqli_query($connection, $sql);
}

//inserts new record in table
//example: insertRecord("decisions","ppnummer, period, decision, kans, tijd","\"$ppnummer\", \"$period\", \"$keus1\", \"$kans\", \"$tijd\"");
function insertRecord($table_name,$names,$values){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="INSERT INTO $table_name (".$names.") VALUES (".$values.")";
	$result=mysqli_query($connection, $sql);
}

function mysqli_result($res,$row=0,$col=0){
    $numrows = mysqli_num_rows($res);
    if ($numrows && $row <= ($numrows-1) && $row >=0){
        mysqli_data_seek($res,$row);
        $resrow = (is_numeric($col)) ? mysqli_fetch_row($res) : mysqli_fetch_assoc($res);
        if (isset($resrow[$col])){
            return $resrow[$col];
        }
    }
    return false;
}


// Counts all entries in a table
function countAllEntries($table_name){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
    if (mysqli_connect_errno()) {
        printf("Connect failed");
        exit();
    }

	$sql="SELECT COUNT(*) FROM $table_name";
	$result=mysqli_query($connection, $sql);
    $value = mysqli_result($result, 0);
	RETURN $value;
}

// Counts some entries in a table
function countSomeEntries($table_name,$condition){
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
    if (mysqli_connect_errno()) {
        printf("Connect failed");
        exit();
    }

	$sql="SELECT COUNT(*) FROM $table_name WHERE $condition";
	$result=mysqli_query($connection, $sql);
    $value = mysqli_result($result, 0);
	RETURN $value;
}

//Function by Jona Linde:
//creates a multidimensional array from the string by exploding using the symbols in $delimiters. 
//Number of dimensions is given by the number of symbols in $delimiters.
//Set delimiters by for example $delimiters=array(";",",");
function multiexplode ($delimiters,$string) {
    $ary = explode($delimiters[0],$string);
    array_shift($delimiters);
    if($delimiters != NULL) {
        foreach($ary as $key => $val) {
             $ary[$key] = multiexplode($delimiters, $val);
        }
    }
    return  $ary;
}

//Function by Jona Linde:
//Lookups one variable in one specific record at random
//example: $role=lookUpRnd("groupcomposition","pp='$ppnummer'","role");
function lookUpRnd($table_name,$condition,$name){
    $connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
    $sql="SELECT * FROM $table_name WHERE ($condition) ORDER BY RAND()";
    $result=mysqli_query($connection, $sql);
    if ($row=mysqli_fetch_array($result)) {
        $value=$row[$name];
    } else $value="";

    RETURN $value;
}

//Instruction menu based upon Roel van Veldhuizen design and improved and automated by Boris van Leeuwen
//You need a table "instructions" with a list of instruction pages. For example:
//		CREATE TABLE `instructions` (
//		  `part` int(11) NOT NULL,
//		  `pagenumber` int(11) default NULL,
//		  `filename` varchar(80) NOT NULL,
//		  `nameinmenu` varchar(80) NOT NULL
//		) ENGINE=MyISAM DEFAULT CHARSET=latin1;
//		INSERT INTO `instructions` VALUES (1, 0, 'instructie1.php', 'Introduction');
//		INSERT INTO `instructions` VALUES (1, 1, 'instructie2.php', 'Payoff table');
//		INSERT INTO `instructions` VALUES (1, 2, 'instructiequestion1.php', 'Question 1');
//		INSERT INTO `instructions` VALUES (1, 3, 'instructiequestion2.php', 'Question 2');
//		INSERT INTO `instructions` VALUES (1, 4, 'instructiesummary.php', 'Summary');
//		INSERT INTO `instructions` VALUES (2, 0, 'instructiepart21.php', 'Introduction part 2');
//		INSERT INTO `instructions` VALUES (2, 1, 'instructiepart22.php', 'Group composition');
//		INSERT INTO `instructions` VALUES (2, 2, 'instructiepart23.php', 'Summary');
//In addition your ppnummers table needs to keep track of the maximum page visited by the subject by the third input variable
//which is equal to 1,2,3 etc for the first part instructions, 101, 102, 103 for the second part instructions, the part is tracked by the fourth input variable

function instructionMenu($page, $ppnr, $vrijgemaakt, $deel){
	//de directory name van de page verwijderen
	$page = substr(strrchr($page, '/'),1);
	//eerst instructietable inlezen en zoeken naar deze pagina
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="SELECT * FROM instructions";
	$result=mysqli_query($connection, $sql);
	$i=1;
	while ($row=mysqli_fetch_array($result)){
		$menuarray[$row['part']][$row['pagenumber']]= array($row['filename'],$row['nameinmenu']);
		if ($page==$row['filename']) {
			$part=$row['part'];			
			$thispage=$row['pagenumber'];			
		}
		$i++;
	}	
	if (!isset($part)) {
		$error="ERROR! this file is not in the instructions table.";
		RETURN $error;
	}
	$count=count($menuarray[$part])+100*($deel-1);
	$menutable="<table align=center cellpadding=3 border=1 class=roundedcorner bgcolor=#cee3f6><tr class=\"menu\">";
	for($counter=1+100*($deel-1);$counter<$count+1;$counter++){
		if ($thispage==$counter) {
			$menutable .="<td class=\"menu\"><font size=3 face=arial color=#000066><u><b>".$menuarray[$part][$counter][1]."</b></u></font></td>";
		} elseif ($vrijgemaakt<$counter) {
			$menutable .="<td class=\"menu\"><font size=3 face=arial color=#000066>".$menuarray[$part][$counter][1]."</font></td>";
		} else {
			$menutable .="<td class=\"menu\"><font size=3 face=arial color=#000066><a Href='".$menuarray[$part][$counter][0]."'>".$menuarray[$part][$counter][1]."</a></font></td>";			
		}
	}
	$menutable .= "</tr></table>";
	RETURN $menutable;
}

function instructionMenuZonderTabelRand($page, $ppnr, $vrijgemaakt, $deel){
	//de directory name van de page verwijderen
	$page = substr(strrchr($page, '/'),1);
	//eerst instructietable inlezen en zoeken naar deze pagina
	$connection = mysqli_connect(HOST,ADMIN, WWOORD, DBNAME);
	$sql="SELECT * FROM instructions";
	$result=mysqli_query($connection, $sql) or die("Couldn't execute query ".$sql);
	$i=1;
	while ($row=mysqli_fetch_array($result)){
		$menuarray[$row['part']][$row['pagenumber']]= array($row['filename'],$row['nameinmenu']);
		if ($page==$row['filename']) {
			$part=$row['part'];			
			$thispage=$row['pagenumber'];			
		}
		$i++;
	}	
	if (!isset($part)) {
		$error="ERROR! this file is not in the instructions table.";
		RETURN $error;
	}
	$count=count($menuarray[$part])+100*($deel-1);
	$menutable="<table align=center cellpadding=3 border=0 class=roundedcorner bgcolor=#cee3f6><tr>";
	for($counter=1+100*($deel-1);$counter<$count+1;$counter++){
		if ($thispage==$counter) {
			$menutable .="<td><font size=3 face=arial color=#000066><u><b>".$menuarray[$part][$counter][1]."</b></u></font></td>";
		} elseif ($vrijgemaakt<$counter) {
			$menutable .="<td><font size=3 face=arial color=#000066>".$menuarray[$part][$counter][1]."</font></td>";
		} else {
	$menutable .="<td><font size=3 face=arial color=#000066><a Href='".$menuarray[$part][$counter][0]."'>".$menuarray[$part][$counter][1]."</a></font></td>";			
		}
	}
	$menutable .= "</tr></table>";
	RETURN $menutable;
}

//Output is a standard start of a htmlpage, with no cache, browsing back disabled, enterkey is disabled in form
function startpage($title) {
	?>
	<html>
	<head>
	<title><?php echo $title; ?></title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<META HTTP-EQUIV="Pragma" CONTENT="no-cache">
	<meta http-equiv="Expires" content="Mon, 01 Jan 1990 12:00:00 GMT">
    <link rel="stylesheet" type="text/css" href="hitstyle.css">
    <script src='jquery-1.11.1.js'></script>
	<script language="JavaScript">
	function blockEnter(evt) {
	  evt = (evt) ? evt : event;
	  var charCode = (evt.charCode) ? evt.charCode : ((evt.which) ? evt.which : evt.keyCode);
	  if (charCode == 13 || charCode == 3) {
	    return false;
	  } else {
	    return true;
	  }
	}
	</script>
    <script type="text/javascript">
        history.pushState(null, null, location.href);
        window.onpopstate = function(event) {
            history.go(1);
        };
    </script>
    <!-- Simulate form behavior-->	
    <script language="JavaScript">
    function postwith (to,p) {
        var myForm = document.createElement("form");
        myForm.method="post" ;
        myForm.action = to ;
        for (var k in p) {
            var myInput = document.createElement("input") ;
            myInput.setAttribute("name", k) ;
            myInput.setAttribute("value", p[k]);
            myForm.appendChild(myInput) ;
        }
        document.body.appendChild(myForm) ;
        myForm.submit() ;
        document.body.removeChild(myForm) ;
    }
    </script>
	</head>
	<?php
}

//returns a array of the variables saved in the cookie with writecookie
//example: $koek=readcookie("beheerder");
//$ppnummer=$koek[0];
function readcookie($variable){
	$cookie_val=$_COOKIE[$variable];
	return explode("-",$cookie_val);
}

//writes a cookie
//example: writecookie("beheerder",$ppnummer);
//or:      writecookie("beheerder",$ppnummer,$role);
function writecookie() {
	$numargs = func_num_args();
	$arg_list = func_get_args();
	$cookie_val="";
	$cookie_val =$arg_list[1];
	for ($i = 2; $i <= LENGTHCOOKIE; $i++) {
		if ($i<$numargs) {
			$cookie_val .="-".$arg_list[$i];
		}
		else {
			$cookie_val .="- ";
		}
	}
	setcookie($arg_list[0], $cookie_val); 
}

?>
