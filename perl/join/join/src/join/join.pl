#!/usr/bin/perl

# 文字列配列を用意.
@array = ('abc', 'def', 'ghi'); # 配列@arrayに'abc', 'def', 'ghi'をリストで指定.

# joinで区切り文字':'を挟んで結合.
$str = join ':', @array; # joinで':'を挟んで@arrayを結合した文字列を$strに代入.

# $strを出力.
print $str."\n"; # $strを出力.
