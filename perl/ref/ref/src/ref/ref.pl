#!/usr/bin/perl

# 変数とリファレンス
$variable = "ABCDE"; # 変数
$reference = \$variable; # 変数のリファレンス
$array_reference = [1, 2, 3]; #配列のリファレンス
$hash_reference = {'key1' => 'value1'}; #ハッシュのリファレンス
$sub_reference = sub { }; #サブルーチンのリファレンス

# refでチェック.
$r1 = ref $variable;
print $r1."\n";
$r2 = ref $reference;
print $r2."\n";
$r3 = ref $array_reference;
print $r3."\n";
$r4 = ref $hash_reference;
print $r4."\n";
$r5 = ref $sub_reference;
print $r5."\n";
