<!DOCTYPE HTML>

<html lang="en">
<head>

    <meta charset="utf-8">
    <meta name="author" content="Lichao Yang">
    <meta name="description" content="Message board ">
    <link rel="icon" href="./images/favicon.ico" type="image/x-icon">
    <title> Message board </title>

    <link rel="stylesheet" href="css/custom.css?version=<?php print time(); ?>" type="text/css">

</head>
<?php
include 'lib/constants.php';
require_once(LIB_PATH . '/Database.php');
print '<!-- make database connection -->';
print PHP_EOL;
$thisDatabaseReader = new Database('lyang12_reader', 'r', DATABASE_NAME);

print '<main>';

// Print the Comment
$sql = 'SELECT fldName , fldTime , fldComment FROM tblComment ORDER BY fldTime DESC ';
$data = array();
$comments = $thisDatabaseReader->select($sql, $data);

print '<h3>Message board</h3>';

if (is_array($comments) && count($comments) > 0) {
    foreach ($comments as $comment) {
        print '<section class="commentArea">';
        print '<p class="username">' . $comment['fldName'] . '</p>';
        print '<p class="date">' . $comment['fldTime'] . '</p>';
        print '<p class="commentContent">' . $comment['fldComment'] . '</p>';
        print '</section>';
    }
}  else {
    print '<p>No Message yet!</p>';
}
print '</main>';


?>

