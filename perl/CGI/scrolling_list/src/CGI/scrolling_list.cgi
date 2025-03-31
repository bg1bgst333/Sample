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
  my @selected_values = $q->param('scrolling_list1'); # 選択されたリストが返ってくる.
  foreach my $selected (@selected_values){ # foreachで配列から要素を取り出す.
    print $selected."\n"; # 選択された項目を出力.
  }

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::scrolling_list"); # <html>タグなどの出力.

  # HTMLフォーム開始タグの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.

  # スクローリングリストの表示.
  print $q->scrolling_list(-name => 'scrolling_list1',
                        -values => ['value1', 'value2', 'value3'],
                        -labels => {
                          value1 => 'label1',
                          value2 => 'label2',
                          value3 => 'label3'
                        },
                        -multiple => 'true'
                      );

  # 改行
  print $q->br; # <br />

  # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
