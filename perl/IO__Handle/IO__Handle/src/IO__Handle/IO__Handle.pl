#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use IO::Handle; # ハンドル.

# IO::Handleオブジェクトの作成.
my $fh = IO::Handle->new; # IO::Handle::newでIO::Handleオブジェクトを生成し, $fhに格納.
# $fhでファイルをオープン.
my $ret = open($fh, ">", "test.txt"); # $fhは"test.txt"を指す.
# 書き込む.
if ($ret){ # trueの時.
  print $fh "ABCDE\n"; # $fhに"ABCDE\n"を書き込む.
  close($fh); # $fhをクローズ.
}
