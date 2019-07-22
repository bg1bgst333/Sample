#!/usr/bin/perl

$str = qq/ABC/; # 文字列"ABC"をqq/ABC/として代入.

print qq/XXX $str YYY\n/; # qqで変数展開, エスケープシーケンスを含めて出力.
