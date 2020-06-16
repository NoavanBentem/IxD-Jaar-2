<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>10b</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "SELECT u.first_name,t.name,AVG(d.temp) AS averageTemp FROM user u LEFT JOIN thing t ON (u.id=t.userId) LEFT JOIN data d ON (d.thingId = t.id) WHERE u.id=1 GROUP BY t.id";
	

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

$row = $result->fetch_assoc();

	do{
		echo json_encode($row)."<br>";
	}while ($row = $result->fetch_assoc());

?>
</body>
</html>