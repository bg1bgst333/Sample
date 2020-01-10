#!/usr/bin/perl

# 対象文字列が複数ある場合.
$str = "ABCDABCAABCCCABC";
$i1 = rindex $str, 'ABC'; # 後ろからABCを探索.
print $i1."\n"; # $i1を出力.
$i2 = rindex $str, 'ABC', 13; # 13番目で終了する.
print $i2."\n"; # $i2を出力.
$i3 = rindex $str, 'ABC', 12; # 12番目で終了する.
print $i3."\n"; # $i3を出力.

# 対象文字列が1つしかない場合.
$str2 = "ABCDE";
$i4 = rindex $str2, 'CD', 2; # 後ろからCDを探索.(2番目で終了する.)
print $i4."\n"; # $i4を出力.
$i5 = rindex $str2, 'CD', 1; # 後ろからCDを探索.(1番目で終了する.)
print $i5."\n"; # $i5を出力.
