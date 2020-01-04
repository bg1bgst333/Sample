#!/usr/bin/perl

# 無名配列の生成
$anonymous_array = [1, 2, 3]; # $anonymous_arrayはリファレンス.

# 無名配列の参照
print $anonymous_array."\n"; # これだとリファレンスなので型情報出力になる.
print @$anonymous_array."\n"; # これだと配列になるが出力されるのは配列のサイズ.
print $$anonymous_array[0]."\n"; # 0番目.
print $$anonymous_array[1]."\n"; # 1番目.
print $$anonymous_array[2]."\n"; # 2番目.
