#!/usr/bin/perl

# 配列の初期化
@array = ('ABCDE', 'aaBCC', 'AaBCC', 'ABACC', 'AAACC', 'aAbCC', 'aAaBC', 'AAbcC'); # リストで文字列配列を初期化.

# 条件に合う文字列の置換.
for $var (@array){
  $var =~ s/A[bB]C/XYZ/; # "AbC"または"ABC"があれば, "XYZ"に置換する.
  print $var."\n"; # $varを出力.
}
