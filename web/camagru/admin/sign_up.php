<?php
include_once('mail.php');

function creation($login, $passwd, $passwd2, $mail, $mail2)
{
	$passwd = hash('whirlpool', $_POST['c_passwd']);
	$passwd2 = hash('whirlpool', $_POST['c_passwd2']);
	$compte = array("login" => $login, "passwd" =>$passwd);
	if (!$login || $passwd !== $passwd2 || !$passwd || $mail !== $mail2 || !$mail)
	{
		echo "Pseudo exist / champs inscription invalides\n";
		return (FALSE);
	}
	else
	{
		if (fetch_login($login))
			return (FALSE);
		$result = add_user($login, $passwd);
			$_SESSION['loggued_on_user'] = ucfirst($login);
		return (TRUE);
	}
}
?>