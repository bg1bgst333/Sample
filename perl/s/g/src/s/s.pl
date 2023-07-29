#!/usr/bin/perl

# 文字列の中で一致する箇所が複数ある場合に, 最初だけ置換.
$str1 = "AabaABCbaABCaaABCaba"; # 対象文字列$str1.
$str1 =~ s/ABC/XYZ/; # この場合は最初だけ置換.
print $str1."\n"; # $str1を出力.

# 文字列の中で一致する箇所が複数ある場合に, 全てを置換.
$str2 = "AabaABCbaABCaaABCaba"; # 対象文字列$str2.
$str2 =~ s/ABC/XYZ/g; # この場合は全てを置換.
print $str2."\n"; # $str2を出力.
