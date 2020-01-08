#!/usr/bin/perl

# 最初から最後まで.
$str = "ABCDE"; # $strを"ABCDE"で初期化.
$ss1 = substr $str, 0; # 0番目から最後までの部分文字列.
print $ss1."\n"; # $ss1を出力.

# 最初から途中まで.
$ss2 = substr $str, 2, 2; # 2番目から2文字の部分文字列.
print $ss2."\n"; # $ss2を出力.

# 途中から最後まで.
$ss3 = substr $str, 2; # 2番目から最後までの部分文字列.
print $ss3."\n"; # $ss3を出力.
