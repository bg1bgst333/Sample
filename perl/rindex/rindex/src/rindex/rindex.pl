#!/usr/bin/perl

# 複数ABCがある場合.
$str = "ABCDABCAABCCCABC";
$i1 = rindex $str, 'ABC'; # 後ろからABCを探索.
print $i1."\n"; # $i1を出力.
