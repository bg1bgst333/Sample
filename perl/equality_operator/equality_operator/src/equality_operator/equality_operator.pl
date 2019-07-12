#!/usr/bin/perl

# 数値の比較
$x = 10;
$y = 10;
if ($x == $y){
  print '$x == $y'."\n";
}
else{
  print '$x != $y'."\n";
}

# 文字列は数値に変換できる場合は変換して比較する.
$s1 = "1ABC";
$s2 = "1XYZ";
if ($s1 == $s2){
  print '$s1 == $s2'."\n";
}
else{
  print '$s1 != $s2'."\n";
}

# 文字列の比較は機能しない.
$str1 = "ABC";
$str2 = "DEF";
if ($str1 == $str2){
  print '$str1 == $str2'."\n";
}
else{
  print '$str1 != $str2'."\n";
}
