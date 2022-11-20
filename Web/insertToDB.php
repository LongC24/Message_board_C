<!DOCTYPE HTML>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="author" content="Lichao">
    <meta name="InsertToDB" content="">
</head>
<?php
include 'lib/constants.php';
require_once(LIB_PATH . '/Database.php');
print '<!-- make database connection -->';
print PHP_EOL;

$thisDatabaseWriter = new Database('UserName_Database', 'w', DATABASE_NAME);


$PASSWORD = 'Some_PW';

$passwordGet = $_GET['password'];
$userName = $_GET['UserName'];
$userComment = $_GET['UserComment'];
$commentTime = $_GET['Time'];


if ($passwordGet == $PASSWORD) {

    $sql = 'INSERT INTO tblComment SET ';
    $sql .= 'fldName = ? ,';
    $sql .= 'fldComment = ? ,';
    $sql .= 'fldTime = ?';
    $data = array();
    $data[] = $userName;
    $data[] = $userComment;
    $data[] = $commentTime;

    $ifInsert = $thisDatabaseWriter->insert($sql, $data);

} else {
    print '<p>You are not authorized insert Data.</p>';
}

?>
</html>
