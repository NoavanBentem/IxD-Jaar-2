<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>B</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "SELECT u.first_name FROM user u LEFT JOIN thing th ON (u.id = th.userId)";
	

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

$row = $result->fetch_assoc();

do {
echo $row["first_name"] . $row["userId"];
} while ($row = $result->fetch_assoc());
	
?>
</body>
</html>