#!/usr/bin/perl

# ファイルから全ての行を読み込んで一致する行だけ出力.
open(IN, "<", "test.txt") || die "open error:"; # "test.txt"をオープン.
while (<IN>){ # INから全ての行を読み込むまで繰り返す.
  if (/A[bB]C/){ # "AbC"または"ABC"に一致する場合.
    print "$.:$_"; # $.は行番号, $_は読み込んだ行文字列.
  }
}
close(IN); # INをクローズ.
