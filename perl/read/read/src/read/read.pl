#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# ファイルtest.txtのファイルサイズを取得する.
my $filesize = -s "test.txt"; # -sでサイズを取得.

# test.txtを開く.
my $ret = open(IN, "<", "test.txt"); # openで"test.txt"を開く.
if ($ret){ # オープン成功.
  # test.txtを読み込む.
  my $buf; # バッファ.
  read(IN, $buf, $filesize); # readで$filesize読み込み, $bufに格納.
  # test.txtを出力.
  print "-----\n"; # 開始.
  print "$buf\n"; # $bufを出力.
  print "-----\n"; # 終了.
}
