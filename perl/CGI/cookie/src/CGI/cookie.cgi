#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータの有無.
if ($q->request_method eq 'POST'){ # 'POST'の時.

  # クッキーの保存,
  my $cookie = $q->cookie(
    -name => 'username',
    -value => $q->param('username'),
    -expires => '+5m'
  );

  # HTTPヘッダの出力.
  print $q->header(-cookie => $cookie); # headerにcookieをセット.

  # HTMLヘッダの出力.
  print $q->start_html("CGI::cookie"); # <html>タグなどの出力.

  # クッキーをセットしたことを表示.
  print "Cookie has been set!\n";
 
  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::cookie"); # <html>タグなどの出力.

  # クッキーがあるかどうか判定.
  my $username = $q->cookie('username'); # $usernameを取得.
  if ($username){ # ある.
    print "Hello, $username!\n";
  }
  else{ # ない.

    # HTMLフォーム開始タグの出力.
    print $q->start_form; # <form>タグの出力.
    print "\n"; # 改行の出力.

    # テキストフィールドの表示.
    print $q->textfield(-name => 'username'); # <input>タグのtype=text.

    # 改行
    print $q->br; # <br />

    # 送信ボタンの出力.
    print $q->submit; # <submit>

    # HTMLフォーム終了タグの出力.
    print $q->end_form; # </form>タグの出力.

  }

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
