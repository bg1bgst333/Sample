#!/usr/bin/perl

# 配列のリファレンス.
$array_reference = [1, 2, 3, 4, 5]; # 無名配列のリファレンス
print $$array_reference[2]."\n"; # 2番目は3.
print $array_reference->[2]."\n"; # アロー演算子で2番目を出力.

# ハッシュのリファレンス.
$hash_reference = {'key1' => 'value1',
                   'key2' => 'value2',
                   'key3' => 'value3'}; # 無名ハッシュのリファレンス
print $$hash_reference{'key2'}."\n"; # キー'key2'の値は'value2'.
print $hash_reference->{'key2'}."\n"; # アロー演算子でキー'key2'の値を出力.
