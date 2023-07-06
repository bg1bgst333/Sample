#!/usr/bin/perl

# 配列のリファレンスの取得.
@ary1 = (10, 20, 30);
$ary1_ref = \@ary1;

# 配列のリファレンスのデリファレンス.
@ary1_deref = @$ary1_ref; # デリファレンス

# 各要素の出力.
print $ary1_deref[0]."\n";
print $ary1_deref[1]."\n";
print $ary1_deref[2]."\n";
