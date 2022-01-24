<?php
    $name = $_POST['name'];
    $phone = $_POST['phone'];
    $date = $_POST['date'];
    $gender = $_POST['gender'];
    $city = $_POST['city'];
    $hobby1 = $_POST['hobby1'];
    $hobby2 = $_POST['hobby2'];
    $hobby3 = $_POST['hobby3'];
    $hobby4 = $_POST['hobby4'];
    $content = $_POST['content'];
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<style>
html, body {
    margin: 0;
}

.title{
    position: relative;
    padding-top: 15px;
    padding-bottom: 15px;
    text-align: center;
    border-bottom: 3px solid white;
    background: rgb(133, 172, 76);
    opacity: 0.7;
}

.container{
    width: 100vw;
    height: 100vh;
}

.application_form{
    width: 90%;
    height: 80%;
    position: relative;
    border: 4px solid rgb(75, 223, 75);
    border-radius: 10px;
    top: 60px;
    left: 30px;
    padding-left: 5rem;
    font-weight: bold; 
}

</style>
<body>
    <div class="container"> 
        <div class="title">
            <h1 style="color:white"> Application Result!!! </h1>
        </div>

        <div class="application_form">
            <div> Name: <?= $name?> [<?= $gender?>] </div>
            <div> Phone: <?= $phone?>). </div>
            <div> Meeting Date: <?= $date?>. </div>
            <div> Lived in: <?= $city?>. </div>
            <div> Hobby: <?= $hobby1?> <?= $hobby2?> <?= $hobby3?> <?= $hobby4?> </div>
            <div> Motivation: <?= $content?> </div>

        </div>
    </div>
    
</body>
</html>
