#!/usr/bin/perl

$str = "ABC"; # 文字列"ABC"を代入.

print "XXX $str YYY\n"; # ダブルクォートの中では変数を展開できる.

print 'AAA $str BBB\n'; # シングルクォートの中では変数は展開されないし, 改行などのエスケープシーケンスも効かない.
