#!/usr/bin/perl

#use strict; # 厳密な文法チェック.

# シンボルを変数に代入.
my $symbol = OUT;
# その変数でファイルをオープン.
my $ret = open($symbol, ">", "test.txt"); # $symbolは"test.txt"を指す.
# 書き込む.
if ($ret){ # trueの時.
  print $symbol "ABCDE\n"; # $symbolに"ABCDE\n"を書き込む.
  close($symbol); # $symbolをクローズ.
}
