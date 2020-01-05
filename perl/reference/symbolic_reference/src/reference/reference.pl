#!/usr/bin/perl

# シンボリックリファレンスの特徴.
$symbolic_reference = "variable"; # 変数$symbolic_referenceに文字列"variable"を代入するという1つ目の解釈.
$$symbolic_reference = 123; # $symbolic_referenceは変数$variableのリファレンスを持つという2つ目の解釈.$variableに123を代入.
print $variable."\n"; # $variableに値が入っているか確認.
print $symbolic_reference."\n"; # $symbolic_referenceの値はどうなっているか確認.
