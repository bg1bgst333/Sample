#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::unescapeHTML"); # <html>タグなどの出力.
  
  # パラメータの取得と表示.
  my $text = $q->escapeHTML($q->param('textarea1')); # 入力されたテキストをエスケープして$textに格納.
  print $text.$q->br."\n"; # $textと"<br />"を出力.

  # 区切り線を表示.
  print "-----".$q->br."\n"; # 区切り線と"<br />"を出力.

  # アンエスケープして表示.
  my $unescaped = $q->unescapeHTML($text); # unescapeHTMLでアンエスケープしたテキストを$unescapedに格納.
  print $unescaped.$q->br."\n"; # $unescapedと"<br />"を出力.
 
  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::unescapeHTML"); # <html>タグなどの出力.

  # HTMLフォーム開始タグの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.

  # テキストエリアの表示.
  print $q->textarea(-name => 'textarea1'); # <textarea>タグ.

  # 改行
  print $q->br; # <br />

   # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
