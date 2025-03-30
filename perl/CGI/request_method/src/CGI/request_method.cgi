#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータの有無.
if ($q->request_method eq 'POST'){ # 'POST'の時.
  
  # CGIヘッダの出力.
  print "Content-type: text/plain\n";
  print "\n";

  # パラメータ取得.
  my $text = $q->param('textfield1'); # 入力されたテキストが返ってくる.
  print $text."\n"; # 入力されたテキストを出力.
  my $password = $q->param('password_field1'); # 入力されたパスワードが返ってくる.
  print $password."\n"; # 入力されたパスワードを出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::request_method"); # <html>タグなどの出力.

  # HTMLフォーム開始タグの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.

  # テキストフィールドの表示.
  print $q->textfield(-name => 'textfield1'); # <input>タグのtype=text.

  # 改行
  print $q->br; # <br />

  # パスワードの表示.
  print $q->password_field(-name => 'password_field1'); # <input>タグのtype=password.

  # 改行
  print $q->br; # <br />

  # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
