<?php
   $db_user = 'noavanbentem';
   $db_pass = 'zoaFeZina0';
   $db_host = 'localhost';
   $db_name = 'noavanbentem';

/* Open a connection */
$conn = new mysqli("$db_host","$db_user","$db_pass","$db_name");

/* check connection */
if ($conn->connect_errno) {
   echo "Failed to connect to MySQL: (" . $conn->connect_errno() . ") " . $conn->connect_error();
   exit();
}
	
function showerror($error,$errornr) {
die("Error (" . $errornr . ") " . $error);
}
	
?>