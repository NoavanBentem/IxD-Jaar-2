<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>4c</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "SELECT * FROM user";

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

$row = $result->fetch_assoc();


//$row["thingId"] . $row["temp"] . $row["dateTime"];
	
echo json_encode($row);
	
?>
</body>
</html>