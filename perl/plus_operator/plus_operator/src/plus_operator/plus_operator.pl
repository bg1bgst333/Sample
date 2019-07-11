#!/usr/bin/perl

# 数値加算
$x = 10;
$y = 20;
$ret = $x + $y;
print "$ret\n";

# 数字文字列なら数値に変換される.
$x1 = "10";
$x2 = "20";
$x = $x1 + $x2;
print "$x\n";

# ダブルクォート関係なく文字列でも数値として加算しようとする.
$s1 = "1ABC";
$s2 = "2DEF";
$str = $s1 + $s2;
print "$str\n";
