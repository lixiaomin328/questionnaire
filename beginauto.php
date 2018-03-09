<?php include 'database.php'; ?>
<?php session_start(); ?>
<?php
ini_set('display_errors', true);

error_reporting(1);

include("common.inc");
if (!isset($_POST['loginpp'])){
    header("Location: index.php?notset");
    exit();
} else {
    $input=$_POST['loginpp'];
    if(!ctype_alnum($input)){
        header("Location: index.php?fail");
        exit();
    } else {
        $ppnr = $input;
    }

    $q = "select count(*) as answer_cnt from `question_answers` where ppnr = \"$ppnr\"";
    $result = $mysqli->query($q) or die($mysqli->error.__LINE__);
    $row = $result->fetch_assoc();
    if ($row['answer_cnt'] > 0){
        header("Location: index.php?fail");
        exit();
    } else {
        $_SESSION['ppnr'] = $ppnr;
        header("Location: question.php?n=1");
    }
}
?>
