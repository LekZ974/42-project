<?php
// include_once('../tests/db.php');
function auth($login, $passwd)
{
	$db = db_connect();
	$s_login = mysqli_real_escape_string($db, $login);
	$query = "SELECT login,password,admin FROM users WHERE login='$login'";
	$result = mysqli_query($db, $query) or die(mysqli_error($db));
	if (mysqli_num_rows($result) === 0)
		return FALSE;
	$row = $result->fetch_row();
	if ($row[0] === $login && $row[1] === $passwd)
	{
		if ($row[2] == 1)
		{
			return ('admin');
		}
		return ('user');
	}
	return (FALSE);
}

function connexion($login, $passwd)
{
	$passwd = hash('whirlpool', $passwd);
	if ($login != "" && $passwd != "") //creer session
	{
		$_SESSION['power'] = auth($login, $passwd);
		if ($_SESSION['power'] != FALSE)
		{
			$_SESSION['loggued_on_user'] = $login;
			return (TRUE);
		}
	}
	$_SESSION['loggued_on_user'] = "";
	echo "identifiants erronés / remplir tout les champs";
	return (FALSE);
}
?>