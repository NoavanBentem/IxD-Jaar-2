<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>4b</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	$query = "SELECT * FROM user";

if (!($result = $mysqli->query($query)))
showerror($mysqli->errno,$mysqli->error);

$row = $result->fetch_assoc();

do {
echo $row["last_name"] . $row["email"];
} while ($row = $result->fetch_assoc());
	
?>
</body>
</html>