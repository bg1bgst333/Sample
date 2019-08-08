#!/usr/bin/perl

# 文字列の分割
$target = <<END; # ENDの前まで格納する.
ABC, DEF, GHI
JKL	MNO,PQR 	STU
END
@ary = split(/\s*,\s*|\s+/, $target); # ','(前後に空白があったらそれも取り除く.)か空白類があれば区切る.
foreach $var (@ary){ # foreachで@aryの取り出し.
  print '$var = '."$var\n"; # $varの出力.
}
