<html>
<head>
<meta name="viewport" content="width=device-width" />
<title>GPIO Pumpkin Web Interface</title>
</head>
<body>
<b>Helloween Kürbis Webinterface:</b><br>
<br>
<form method="get" action="index.php">
<b>Bitte Sequenz eingeben</b><br>
<input type="input" value="" name="Eingabe"/><br><br>
<input type="submit" value="Starte MorseCode" name="morse"/><br><br>
<input type="submit" value="BlinkRandom" name="BlinkRandom"/><br><br>
<input type="submit" value="KillPumpkin" name="KillPumpkin"/><br><br>
</form>

<?php
$modeon26 = trim(@shell_exec("sudo /usr/local/bin/gpio -g mode 26 out"));

if (isset($_GET["morse"]) && $_GET["morse"]!="") {
	$val = trim(@shell_exec("sudo pkill pumpkinpi"));	
	$val = trim(@shell_exec("sudo pkill morsepi"));	
	echo "Killed all other programs!   Code working on sequence: ". $_GET["Eingabe"];
	flush();
	$val = trim(@exec("sudo /home/development/scripts/morsepi " . $_GET["Eingabe"]));	
}
if (isset($_GET["BlinkRandom"])&& $_GET["BlinkRandom"]!="") {
	
	echo "killing other processes ";
	$val = trim(@shell_exec("sudo pkill pumpkinpi"));	
	$val = trim(@shell_exec("sudo pkill morsepi"));	
	flush();
	$val = trim(@exec("sudo /home/development/scripts/pumpkinpi"));	
	
}
if (isset($_GET["KillPumpkin"])) {
	$val = trim(@shell_exec("sudo pkill pumpkinpi"));	
	$val = trim(@shell_exec("sudo pkill morsepi"));	
	flush();
}

?>

</body>
</html>
