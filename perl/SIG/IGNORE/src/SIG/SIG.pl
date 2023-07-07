#!/usr/bin/perl

# 'IGNORE'をセット.
$SIG{'INT'} = 'IGNORE'; # $SIG{'INT'}に'IGNORE'をセット.

# 10個の要素を1秒ごとに取り出す.
@array = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10); # 10個の要素の配列を初期化.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print '$var = '."$var\n"; # $varの値を出力.
  sleep 1; # 1秒休止.
}
