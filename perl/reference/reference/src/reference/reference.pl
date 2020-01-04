#!/usr/bin/perl

# リファレンスの取得
$variable = "ABCDE";
$reference = \$variable; # \を付けるとリファレンスを表す.

# リファレンスの参照
print $reference."\n"; # これだとリファレンスの情報(アドレスや型など.)を出力するだけになってしまう.
print $$reference."\n"; # これで参照先の値を出力する.
