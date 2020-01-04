#!/usr/bin/perl

# リファレンスのリファレンスを取得 
$variable = "ABCDE";
$reference_to_reference = \\$variable; # \\を付けるとリファレンスのリファレンスを表す.

# リファレンスのリファレンスを参照
print $reference_to_reference."\n"; # これだとリファレンスのリファレンスの情報(アドレスや型など.)を出力する.
print $$reference_to_reference."\n"; # これだとリファレンスの情報(アドレスや型など.)を出力する.
print $$$reference_to_reference."\n"; # これだと値を出力.
