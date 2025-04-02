#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Cookie; # Cookie.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータの有無.
if ($q->request_method eq 'POST'){ # 'POST'の時.

  # クッキーの保存,
  my $cookie = CGI::Cookie->new(
    -name => 'username',
    -value => $q->param('username'),
    -expires => '+5m'
  ); # CGI::Cookieでセット.

  # HTTPヘッダの出力.
  print $q->header(-cookie => $cookie); # headerにcookieをセット.

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Cookie"); # <html>タグなどの出力.

  # クッキーをセットしたことを表示.
  print "Cookie has been set!\n";
 
  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # 'POST'以外.('GET'など.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Cookie"); # <html>タグなどの出力.

  # クッキーがあるかどうか判定.
  my %cookies = CGI::Cookie->fetch; # %cookiesをfetchで取得.
  my $username = $cookies{'username'} ? $cookies{'username'}->value : undef; # キーが'username'となる要素があれば値をvalueで取得.
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
