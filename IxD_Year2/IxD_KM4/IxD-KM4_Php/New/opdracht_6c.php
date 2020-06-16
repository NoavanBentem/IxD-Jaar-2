<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>URL GET INSERT</title>
</head>
<body>
<?php
	include("connectFile.php");
	session_start();
	
	$thingId = $_SESSION["thingId"];
	$temp = $_GET["temp"];
	
	$query = "INSERT INTO `data` (`id`, `thingId`, `temp`, `dateTime`) VALUES (NULL, $thingId, $temp, current_timestamp());";

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

	
?>
</body>
</html>