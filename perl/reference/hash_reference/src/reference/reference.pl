#!/usr/bin/perl

# ハッシュのリファレンスの取得.
%hash1 = ('key1' => 10,
          'key2' => 20,
          'key3' => 30);
$hash1_ref = \%hash1;

# ハッシュのリファレンスのデリファレンス.
%hash1_deref = %$hash1_ref; # デリファレンス

# 各要素の出力.
print $hash1_deref{'key1'}."\n";
print $hash1_deref{'key2'}."\n";
print $hash1_deref{'key3'}."\n";
