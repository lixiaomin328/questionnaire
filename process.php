<?php include 'database.php'; ?>
<?php session_start(); ?>
<?php
if (!isset($_SESSION['ppnr'])){
    header("Location: login.php?fail");
    exit();
} else {
   $ppnr = $_SESSION['ppnr'];
}
      //Check to see if score is set_error_handler
	if (!isset($_SESSION['score'])){
	   $_SESSION['score'] = 0;
	}

//Check if form was submitted
if($_POST){
	$number = $_POST['number'];
	$selected_choice = $_POST['choice'];
	$next=$number+1;
	$total=4;

	//Get total number of questions
	$query="SELECT * FROM `questions`";
	$results = $mysqli->query($query) or die($mysqli->error.__LINE__);
	$total=$results->num_rows;

	//Get correct choice
	$q = "select * from `choices` where question_number = $number and is_correct=1";
	$result = $mysqli->query($q) or die($mysqli->error.__LINE__);
	$row = $result->fetch_assoc();
	$correct_choice=$row['id'];

    $insert_query="INSERT INTO `question_answers` (ppnr,question_id,choice_id) VALUES (\"$ppnr\",$number,$selected_choice)";
    $result = $mysqli->query($insert_query) or die($mysqli->error.__LINE__);

	//compare answer with result
	if($correct_choice == $selected_choice){
		$_SESSION['score']++;
	}

	if($number == $total-1) {
        header("Location: beauty_contest.php?n=".$next."&score=".$_SESSION['score']);
    } else if($number == $total){
		header("Location: final.php");
		exit();
	} else {
	        header("Location: question.php?n=".$next."&score=".$_SESSION['score']);
	}
}
?>