<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>4b</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "SELECT th.location, COUNT(d.temp) AS tempEntries, AVG(d.temp) AS averageTemp FROM data d LEFT JOIN thing th ON (d.thingId = th.id) GROUP BY thingId";
	

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

$row = $result->fetch_assoc();

	do{
		echo json_encode($row)."<br>";
	}while ($row = $result->fetch_assoc());

?>
</body>
</html>