#!/usr/bin/perl

# サブルーチンのリファレンスの取得.
$test_sub_ref = \&test_sub;

# サブルーチンのリファレンスのデリファレンス.
$result = &$test_sub_ref(5); # デリファレンスと呼び出し.

# 出力
print $result."\n";

# サブルーチンの定義.
sub test_sub{
  return $_[0] * 10;
}
