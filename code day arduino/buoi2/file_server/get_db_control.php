<?php
//if ($_SERVER['REQUEST_METHOD'] === 'POST'){
	//if (isset($_POST['DV_ID'])) {

	  	$username="id6561449_ceec";
		$password="123456";
		$server = "localhost";
		$dbname = "id6561449_iot_training";

		$connect=new mysqli($server,$username,$password,$dbname);

		if ($connect->connect_error) {
			die("ERROR".$connect->connect_error);
			exit();
		}
		
		//$Device_Id=$_POST['DV_ID'];
		$Device_Id='LED13';

		$sql = "SELECT STATUS FROM DEVICES WHERE DV_ID='$Device_Id'";
		$result = $connect->query($sql);

		if(!$result) {
			die("ERROR".$connect->connect_error);
			exit();
		}

		//Tham chieu den tung phan tu trong table
		$row=$result -> fetch_array(MYSQLI_ASSOC);
		echo $row['STATUS'];
	//}
//}
?>