<?php
	session_start();
	include_once('sign_in.php');
	include_once('sign_up.php');

	if ($_POST['submit1'] === "OK")
	{
		if (connexion($_POST['login'], $_POST['passwd']))
			header('Location: acc_user.php');
	}
	if ($_POST['submit2'] === "OK")
	{
		if (creation($_POST['c_login'], $_POST['c_passwd'], $_POST['c_passwd2'], $_POST['mail'], $_POST['mail2']))
			header('Location: acc_user.php');
	}
	else if ($_SESSION['loggued_on_user'] != "")
		header('Location: ../index.php');
?>
<head><?php require ('../includes/header.php'); require ('../includes/footer.php');?></head>
<body>
<content class="auth">
<ul class="connexion">
	<link rel="stylesheet" type="text/css" href="../style/style.css">
	<h2>Connexion</h2>
	<form action="" method="POST">
		<h3>Login :</h3> <input type="text" name="login"><br /><br />
		<h3>Mot de passe :</h3> <input type="password" name="passwd"><br />
		<input type="submit" name="submit1" value="OK"><br /><br /><br />
	</form>
</ul>
<ul class="creation">
	<h2>Création Compte</h2>
	<form action="" method="POST">
		<h3>Login :</h3> <input type="text" name="c_login"><br /><br />
		<h3>Mot de passe :</h3> <input type="password" name="c_passwd"><br />
		<h3>Répeter mot de passe :</h3> <input type="password" name="c_passwd2"><br />
		<h3>Mail :</h3> <input type="mail" name="mail"><br />
		<h3>Confirmer mail :</h3> <input type="mail" name="mail2"><br />
		<input type="submit" name="submit2" value="OK"><br /><br /><br />
	</form>
</ul>
</content>
</body>