#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # CGIヘッダの出力.
  print "Content-type: text/plain\n";
  print "\n";

  # リクエストの読み込み.
  my $buf; # バッファ.
  read(STDIN, $buf, $ENV{'CONTENT_LENGTH'});
  print $buf;

}
else{ # 'POST'以外.('GET'など.)

  # CGIオブジェクトの作成.
  my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::checkbox(-name,-checked,-value,-label)"); # <html>タグなどの出力.

  # HTMLフォーム開始タグの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.

  # チェックボックスの出力.
  print $q->checkbox(-name => 'checkbox1',
                   -checked => 'checked',
                   -value => 'ON',
                   -label => 'check ok'); # <input>タグのtype=checkboxを出力.

  # 改行
  print $q->br; # <br />

  # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
