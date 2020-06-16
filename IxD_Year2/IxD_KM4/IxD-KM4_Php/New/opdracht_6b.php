<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>6</title>
</head>
<body>
<?php
	include("connectFile.php");
	
	session_start();
	$thingId = $_GET["thingId"];
	$password = $_GET["password"];
	
	$query = "SELECT * FROM thing WHERE id = $thingId and password = '$password'";
	

	
	if (!($result = $mysqli->query($query))){
		showerror($mysqli->errno,$mysqli->error);
		}

	$row = $result -> fetch_assoc();
	//$row = mysqli_fetch_assoc($result);
	//printf ("%s (%s)\n", $row["thingId"], $row["password"]);
	echo $row["id"];
	
	//echo $result -> fetch_assoc();
	//printf('%s',$row["thingId"], $row["password"]);

	if ($thingId == $row["id"]){
			echo session_id();
		$_SESSION["thingId"]=$row["id"];

		}	else{
			print("0");
		}
?>
</body>
</html>