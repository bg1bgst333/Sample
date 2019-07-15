#!/usr/bin/perl

# ファイルのオープン
$ret = open(IN, "<", "test.txt"); # "test.txt"は存在するのでtrueが返る.
if ($ret){ # trueの時.
  print "open success \"test.txt\".\n"; # "open success "test.txt"."と出力.
  close(IN); # ファイハンドル"IN"をクローズ.
}
