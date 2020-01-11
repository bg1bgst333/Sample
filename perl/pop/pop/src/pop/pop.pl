#!/usr/bin/perl

# リストで配列を初期化.
@array = (10, 20, 30); # 10, 20, 30という3要素の配列を初期化.
foreach $var (@array){ # foreachで@arrayから要素を取り出し, $varに格納.
  print "$var\n"; # $varの出力.
}

# 末尾から要素を取り出す.
$elem = pop(@array); # popで取り出し.
print "$elem\n"; # 取り出した要素を出力.

# 再度配列を出力.
foreach $var (@array){ # 残りの分繰り返す.
  print "$var\n"; # 残りを出力.
}
