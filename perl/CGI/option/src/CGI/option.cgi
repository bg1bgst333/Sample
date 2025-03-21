#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.
  
  # CGIヘッダの出力.
  print "Content-type: text/plain\n";
  print "\n";

  # パラメータ取得.
  my $selected_value = $q->param('select1'); # 選択された項目が返ってくる.
  print $selected_value."\n"; # 選択された項目を出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::option"); # <html>タグなどの出力.

  # HTMLフォーム開始タグの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.

  # セレクトボックスの出力.
  print $q->Select({ -name => 'select1'},
                    $q->option({ -value => 'value1'}, 'label1'),
                    $q->option({ -value => 'value2'}, 'label2'),
                    $q->option({ -value => 'value3'}, 'label3')
                  ); # セレクトボックスに3つのoption要素を設定して出力.

  # 改行
  print $q->br; # <br />

  # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
