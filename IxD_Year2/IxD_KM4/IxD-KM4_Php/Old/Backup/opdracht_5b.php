<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>Url GET</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "INSERT INTO `data` (`id`, `thingId`, `temp`, `dateTime`) VALUES (NULL, '3', '50', current_timestamp());";

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

	
?>
</body>
</html>