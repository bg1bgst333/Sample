#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# $fhでファイルをオープン.
my $ret = open(my $fh, ">", "test.txt"); # $fhは"test.txt"を指す.(Perl 5.6からは, openにundefな変数が渡されると無名型グロブを返す.)
# 書き込む.
if ($ret){ # trueの時.
  print $fh "ABCDE\n"; # $fhに"ABCDE\n"を書き込む.
  close($fh); # $fhをクローズ.
}
