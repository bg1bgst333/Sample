#!/usr/bin/perl

# アルファベットの列の後に数字の列が来る文字列のパターン.
$str = "aDg372"; # $strに"aDg372"を代入.
if ($str =~ /([a-zA-Z]+)(\d+)/){ # アルファベット列の後に数字列.
  print '$1 = '.$1."\n"; # アルファベット列.
  print '$2 = '.$2."\n"; # 数字列.
}