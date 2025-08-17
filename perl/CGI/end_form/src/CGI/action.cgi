#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::end_form"); # <html>タグなどの出力.

# パラメータの有無.
my @keys = $q->param; # キー配列が返ってくる.
if (@keys == 0){ # 初回アクセス.
  print $q->start_form; # <form>タグの出力.
  print "\n"; # 改行の出力.
  print "<input name=\"key1\" value=\"value1\">\n"; # key1
  print "<input name=\"key2\" value=\"value2\">\n"; # key2
  print "<input type=\"submit\" value=\"submit\">\n"; # submit
  print $q->end_form; # </form>タグの出力.
}
else{ # リクエスト後.
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
}

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
