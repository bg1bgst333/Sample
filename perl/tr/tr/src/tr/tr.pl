#!/usr/bin/perl

# 配列の初期化
@array = ('ABCDE', 'aaBCC', 'AaBCC', 'ABACC', 'AAACC', 'aAbCC', 'aAaBC', 'AAbcC'); # リストで文字列配列を初期化.

# 条件に合う文字の置換.
for $var (@array){
  $var =~ tr/[aC]/[Ac]/; # 'a'は'A'に, 'C'は'c'に置換.
  print $var."\n"; # $varを出力.
}
