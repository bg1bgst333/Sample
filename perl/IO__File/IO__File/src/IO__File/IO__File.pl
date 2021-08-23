#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use IO::File; # ファイル.

# IO::Fileオブジェクトの作成.
my $fh = IO::File->new; # IO::File::newでIO::Fileオブジェクトを生成し, $fhに格納.(IO::FileはIO::Handleを継承.)
# $fhでファイルをオープン.
my $ret = open($fh, ">", "test.txt"); # $fhは"test.txt"を指す.
# 書き込む.
if ($ret){ # trueの時.
  print $fh "ABCDE\n"; # $fhに"ABCDE\n"を書き込む.
  close($fh); # $fhをクローズ.
}
