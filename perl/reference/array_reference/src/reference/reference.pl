#!/usr/bin/perl

# 配列のリファレンスの取得.
@ary1 = (10, 20, 30);
$ary1_ref = \@ary1;

# 配列のリファレンスのデリファレンス.
print @$ary1_ref[0]."\n";
print @$ary1_ref[1]."\n";
print @$ary1_ref[2]."\n";
