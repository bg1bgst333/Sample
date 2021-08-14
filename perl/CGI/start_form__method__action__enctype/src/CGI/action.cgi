#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::start_form(-method,-action,-enctype)"); # <html>タグなどの出力.

# パラメータの取得.
my @keys = $q->param; # キー配列が返ってくる.
my $i = 0; # $iを0で初期化.
while ($i < @keys){ # パラメータ数未満の間繰り返す.
  print $keys[$i]." = ".$q->param($keys[$i]); # $i番目のキーと, $i番目の値を出力.
  if ($i == @keys - 1){ # 最後のパラメータ.
    last; # 抜ける.
  }
  else{ # 最後ではない.
    print "<br />\n"; # <br />と改行の出力.
  }
  $i++; # $iのインクリメント.
}

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
