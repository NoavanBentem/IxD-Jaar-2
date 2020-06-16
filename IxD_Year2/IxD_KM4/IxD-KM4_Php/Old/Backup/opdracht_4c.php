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


echo $row["last_name"] . $row["email"];
	
echo json_encode($row);
	
?>
</body>
</html>