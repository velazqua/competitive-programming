<?php
 
// Create a new blank image 
$image = imagecreate(200, 30); 
 
// Assign the background color 
imagecolorallocate($image, 0x00, 0x00, 0xFF); 
 
// Assign the text color to a variable, to use it later 
$set_text_color = imagecolorallocate($image, 0xFF, 0xFF, 0xFF); 
 
$text1 = $_GET["text1"];
$text2 = $_GET["text2"];
 
$text = $text1." are ".$text2;
 
// Write on the image 
imagettftext($image, 14, 0, 5, 20, $set_text_color, '04b24', $text); 
 
// Assign the correct Header 
header('Content-Type: image/PNG'); 
 
// Show the picture 
imagepng($image); 
 
// Destroy the temp file 
imagedestroy($image); 
 
?>
