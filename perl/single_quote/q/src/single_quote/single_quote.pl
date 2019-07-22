#!/usr/bin/perl

$str = q/ABC/; # 文字列'ABC'をq/ABC/として代入.

print qq/XXX $str YYY\n/; # qq/~/の中では変数を展開できる.

print q/AAA $str BBB\n/; # q/~/の中では変数は展開されないし, 改行などのエスケープシーケンスも効かない.
