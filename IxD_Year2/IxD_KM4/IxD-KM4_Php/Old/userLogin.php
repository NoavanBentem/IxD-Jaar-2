<?php
	include "connectFile.php";
	session_start();
	$email = $_POST["email"];
	$password = $_POST["password"];
	
	$sql = "SELECT * FROM user WHERE email = '$email'";
	
	$result = $conn->query($sql);
	
	
	if ($result->num_rows > 0){
		echo "Er is iets";
		while($row = $result->fetch_assoc()){
			//check password with user
			//$hash = $row['password'];
			if($password==$row['password']){
				echo" yay";	
			} else {
				echo " Oh no";
			}
		}
	}
	else{
		echo "no results";
	}
	
	$conn->close();

?>
