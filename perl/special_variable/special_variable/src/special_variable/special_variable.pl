#!/usr/bin/perl

# ファイルから全ての行を読み込んで出力.
open(IN, "<", "test.txt") || die "open error:"; # "test.txt"をオープン.
while (<IN>){ # INから全ての行を読み込むまで繰り返す.
  print "$.:$_"; # $.は行番号, $_は読み込んだ行文字列.
}
close(IN); # INをクローズ.
