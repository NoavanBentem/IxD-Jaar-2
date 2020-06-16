<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>5.1</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "INSERT INTO `data` (`id`, `thingId`, `temp`, `dateTime`) VALUES (NULL, '3', '50', '2020-05-20 13:22:02');";

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

	
?>
</body>
</html>