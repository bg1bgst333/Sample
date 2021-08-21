#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# パラメータの有無.
if ($ENV{'REQUEST_METHOD'} eq 'POST'){ # 'POST'の時.

  # CGIヘッダの出力.
  print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
  print "\n"; # "\n"を出力.

  # リクエストの読み込み.
  my $buf; # バッファ.
  read(STDIN, $buf, $ENV{'CONTENT_LENGTH'});
  print $buf

}
else{ # 'POST'以外.('GET'など.)

  # CGIオブジェクトの作成.
  my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::submit"); # <html>タグなどの出力.

  # HTMLフォームの出力.
  print $q->start_form(-enctype => $q->URL_ENCODED); # <form>タグの出力.
  print "\n"; # 改行の出力.
  print $q->textfield(-name => 'key1', -value => 'value1'); # key1
  print $q->textfield(-name => 'key2', -value => 'value2'); # key2
  print $q->submit; # submit
  print $q->end_form; # </form>タグの出力.

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
