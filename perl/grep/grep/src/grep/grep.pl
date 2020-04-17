#!/usr/bin/perl

# 1以上の整数である要素のみ取り出す.
@plus = grep $_ >= 1, 5, -2, 12, 0, 4, -20, 33, 100, -1; # grepで1以上のリストを取得し, @plusに格納.
foreach $var (@plus){ # foreachで@plusから要素を取り出し, $varに格納.
  print "$var\n"; # $varの出力.
}
