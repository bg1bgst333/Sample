#!/usr/bin/perl

# 数値があっても文字列で比較する.
$s1 = "1ABC";
$s2 = "1XYZ";
if ($s1 eq $s2){
  print '$s1 eq $s2'."\n";
}
else{
  print '$s1 ne $s2'."\n";
}

# 文字列の一致
$s3 = "1ABC";
if ($s1 eq $s3){
  print '$s1 eq $s3'."\n";
}
else{
  print '$s1 ne $s3'."\n";
}
