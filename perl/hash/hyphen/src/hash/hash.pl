#!/usr/bin/perl

# 先頭に-(ハイフン)を付けることでキーを指定.
%hash = (-key1 => 'value1',
         -key2 => 'value2',
         -key3 => 'value3');

# -(ハイフン)でキーを指定し, 値を参照し, 出力.
print $hash{-key1}."\n";
print $hash{-key2}."\n";
print $hash{-key3}."\n";

# -(ハイフン)のキーと, 文字列のキーは違う.
print $hash{"key1"}."\n";
print $hash{"key2"}."\n";
print $hash{"key3"}."\n";
