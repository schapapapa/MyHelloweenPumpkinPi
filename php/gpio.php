<html>
<head>
<meta name="viewport" content="width=device-width" />
<title>GPIO Pumpkin Web Interface</title>
</head>
<body>
Pumpkin Pi Steuerung:
<form method="get" action="index.php">
<input type="submit" value="17_Licht_ein" name="17_Licht_ein"/>
<input type="submit" value="17_Licht_aus" name="17_Licht_aus"/>
<input type="submit" value="25_Licht_ein" name="25_Licht_ein"/>
<input type="submit" value="25_Licht-aus" name="25_Licht_aus"/>
<input type="submit" value="PumpkinPi" name="PumpkinPi"/>
<input type="submit" value="KillPumpkin" name="KillPumpkin"/>
</form>

<?php
$modeon17 = trim(@shell_exec("sudo /usr/local/bin/gpio -g mode 17 out"));
$modeon25 = trim(@shell_exec("sudo /usr/local/bin/gpio -g mode 25 out"));

if (isset($_GET["17_Licht_ein"])) {
	$val = trim(@shell_exec("sudo /usr/local/bin/gpio -g write 17 0"));	
	echo "Licht 17 ist nun an!";
}
if (isset($_GET["17_Licht_ein"])) {
	$val = trim(@shell_exec("sudo /usr/local/bin/gpio -g write 17 1"));	
	echo "Licht 17 ist nun aus!";
}
if (isset($_GET["25_Licht_ein"])) {
	$val = trim(@shell_exec("sudo /usr/local/bin/gpio -g write 25 0"));
	echo "Licht 25 ist nun an!";	
}
if (isset($_GET["25_Licht_ein"])) {
	$val = trim(@shell_exec("sudo /usr/local/bin/gpio -g write 25 1"));	
	echo "Licht 25 ist nun aus!";
}
if (isset($_GET["PumpkinPi"])) {
	$val = trim(@shell_exec("sudo /usr/local/bin/pumpkinpi"));	
	echo "pumpkin working";
}
if (isset($_GET["KillPumpkin"])) {
	$val = trim(@shell_exec("sudo pkill pumpkinpi"));	
	echo "pumpkin working";
}

?>

</body>
</html>