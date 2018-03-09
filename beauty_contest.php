<?php include "database.php"; ?>
<?php session_start(); ?>
<?php
include("common.inc");
startpage("Beauty Contest");
//Set question number
$number = (int) $_GET['n'];

//Get total number of questions
$query = "select * from questions";
$results = $mysqli->query($query) or die($mysqli->error.__LINE__);
$total=$results->num_rows;
if(isset($_GET['notset'])) {?>
<script>
    alert('You must input your MTurk number')
</script><?php
};?>
<head>
    <meta charset="utf-8" />
    <title>Questionnaire</title>
    <link rel="stylesheet" href="css/style.css" type="text/css" />
</head>
<body>
<div id="container">
    <header>
        <div class="container">
            <h1>Questionnaire</h1>
        </div>
    </header>
    <main>
        <div class="container">
            <div class="current">Question <?php echo $number; ?> of <?php echo $total; ?></div>
<div id="contentwrapper">
    <div id="loginbox">
        <form name="form2" method="post" action="process.php">
            <table>
                <p>Now all the participants are going to compete for a big bonus.
                    Each of the players needs to type a number. </p>
                <p>from 0 to 100, the person with a number closest to 1/3 of the average (average of everyone's number) will get $10.</p>
                <p>If multiple people choose the same number, they are going to split the bonus.</p>
                <p>Please input your number here:  <input type="text" style="width: 250px;" name="choice" autocomplete="off"></p>
                <input type='hidden' name='scwidth' id="test1" value='1'>
                <input type='hidden' name='scheight' id="test2" value='2'>
                <input type="submit" style="width: 47.5%; margin-right:5%;" class="sexybutton" name="Proceed" value="Submit">
            </table>
            <input type="hidden" name="number" value="<?php echo $number; ?>" />
        </form>
    </div>
</div>
<script type="text/javascript">
    document.getElementById('test1').value = screen.width;
    document.getElementById('test2').value = screen.height;
</script>
        </main>
</body>
</html>
