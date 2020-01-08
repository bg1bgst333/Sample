#!/usr/bin/perl

# 最初から探索.
$str = "ABCDEAABCEACABCDCDE"; # $strを"ABCDEAABCEACABCDCDE"で初期化.
$i1 = index $str, 'ABC'; # 'ABC'の位置を取得.
print $i1."\n"; # $i1を出力.

# 途中から探索.
$i2 = index $str, 'ABC', 2; # 0文字目から数えて2文字目から探索して, 'ABC'の位置を取得.
print $i2."\n"; # $i2を出力.
