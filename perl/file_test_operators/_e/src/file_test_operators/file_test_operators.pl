#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# ファイルtest.txtの存在を確認する.
if (-e "test.txt"){ # 存在するなら真.
  print "test.txt exists.\n"; # "test.txt exists."と出力.
}
else{ # 存在しないなら偽.
  print "test.txt not found.\n"; # "test.txt not found."と出力.
}
