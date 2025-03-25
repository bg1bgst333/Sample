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
  print $q->start_html("CGI::escapeHTML"); # <html>タグなどの出力.
  
  # パラメータの取得と表示.
  my $user = $q->param('textfield1'); # 入力されたuserが返ってくる.
  print "user: ".$q->escapeHTML($user).$q->br."\n"; # 入力されたuserをエスケープして出力.
  my $pass = $q->param('password_field1'); # 入力されたpassが返ってくる.
  print "pass: ".$q->escapeHTML($pass).$q->br."\n"; # 入力されたpassをエスケープして出力.
  my $token = $q->param('token'); # tokenが返ってくる.
  print "token: ".$token.$q->br."\n"; # tokenを出力.
 
  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::escapeHTML"); # <html>タグなどの出力.

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

  # 隠しトークンのセット.
  print $q->hidden(-name => 'token', -value => 'xyz'); # <hidden>タグで隠し要素をセット.

   # 送信ボタンの出力.
  print $q->submit; # <submit>

  # HTMLフォーム終了タグの出力.
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
