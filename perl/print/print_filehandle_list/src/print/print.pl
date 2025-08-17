#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# ファイルのオープン
my $ret = open(OUT, ">", "test.txt"); # "test.txt"を書き込みモードで開く.(ファイルハンドルはOUT.)
if ($ret){ # trueの時.
  print OUT "ABCDE"; # OUTに"ABCDE"を出力.(ファイルハンドルの後ろはカンマで区切らない.)
  close(OUT); # OUTをクローズ.
}
