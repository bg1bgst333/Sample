#!/usr/bin/perl

# 5つの要素を1秒ごとに取り出す.
@array = (1, 2, 3, 4, 5); # 1, 2, 3, 4, 5という5要素の配列を初期化.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print '$var = '."$var\n"; # $varの値を出力.
  sleep 1; # 1秒休止.
}
