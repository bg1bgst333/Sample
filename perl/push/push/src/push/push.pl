#!/usr/bin/perl

# リストで配列を初期化.
@array = (10, 20, 30); # 10, 20, 30という3要素の配列を初期化.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print "$var\n"; # $varの出力.
}

# 要素40を末尾に追加.
push(@array, 40); # pushで40を末尾に追加.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print "$var\n"; # $varの出力.
}
