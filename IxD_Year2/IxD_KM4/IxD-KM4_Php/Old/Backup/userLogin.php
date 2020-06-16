<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<title>User login</title>
</head>
<body>
<?php
	include "connectFile.php";
	
	session_start();
	$email = $_POST["email"];
	$password = $_POST["password"];
	
	$sql = "SELECT * FROM user WHERE email = '$email'";
	
	$result = $conn->query($sql);
	
	/*
	if (!($result = $mysqli->query($query))){
		showerror($mysqli->errno,$mysqli->error);
		}
	*/

	//$row = $result -> fetch_assoc();
	//$row["id"];
	
	if ($result->num_rows > 0){
		echo "Er is iets";
		while($row = $result->fetch_assoc()){
			//check password with user
			//$hash = $row['password'];
			
			if($password=$row['password']){
				echo"yay";	
			} else {
				echo "Oh no";
			}
		}
	}
	else{
		echo "no results";
	}
	
	$conn->close();

	/*
	if ($row["id"]){
		echo $row;
		session_id();
		$_SESSION["thingId"]=$row["id"];
		header('Location: thingOverview.php');

		}	else{
		echo("0");
			//header('Location: login.php');
		}
	*/
?>
</body>
</html>