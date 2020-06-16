<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>URL GET INSERT</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	if (isset($_GET['sessieId'])) {
		$sId=htmlspecialchars($_GET['sessieId']);
		session_id($sId);
	}
	
	session_start();
	
	$thingId = $_SESSION["thingId"];
	$temp = $_GET["temp"];
	
	if (isset($_SESSION["thingId"]) && $_SESSION["thingId"]!=0) {
		
		$query = "INSERT INTO `data` (`id`, `thingId`, `temp`, `dateTime`) VALUES (NULL, $thingId, $temp, current_timestamp());";
		
		if (!($result = $mysqli->query($query)))
		showerror($mysqli->errno,$mysqli->error);
		
		echo $_SESSION["thingId"];

	} else {
		echo "0";
	}

	
?>
</body>
</html>