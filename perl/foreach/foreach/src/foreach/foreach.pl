#!/usr/bin/perl

# リストで配列を初期化.
@array = (100, 200, 300); # 100, 200, 300という3要素の配列を初期化.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print '$var = '."$var\n"; # $varの出力.
}
