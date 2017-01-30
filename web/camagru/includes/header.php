<?php session_start(); ?>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="/camagru/style/style.css"/>
	<title>Camagru</title>
</head>
<header>
	<h1><a href="/camagru/index.php">Camagru</a></h1>
	<ul class= "log">
		<?php if ($_SESSION['loggued_on_user'] != "")
			echo '<p>What\'s up '.$_SESSION['loggued_on_user'].'?!';
		?>
	</ul>
	<ul class="gestion">
		<li><a href="/camagru/oth/galerie.php">Galerie</a></li>
		<?php
		if ($_SESSION['loggued_on_user'] == "")
			echo '<li><a href="/camagru/admin/index_admin.php">Connexion</a></li>';
		else if ($_SESSION['loggued_on_user'] != "")
		{
			if ($_SESSION['power'] == "admin")
				echo '<li><a href="/camagru/admin/admin.php">Administration</a></li>';
			else
				echo '<html><li><a href="/camagru/admin/acc_user.php">Compte</a></li><html>';
			echo '<ul class="deconnexion">
					<li><a href="/camagru/admin/log_out.php">Deconnexion</a></li>
				</ul>';
		}
		?>
	</ul>
	<ul class="menu">
		<li><a href="/camagru/index.php">Accueil</a></li>
		<li><a href="/camagru/oth/galerie_user.php">Ma galerie</a></li>
	</ul>
</header>