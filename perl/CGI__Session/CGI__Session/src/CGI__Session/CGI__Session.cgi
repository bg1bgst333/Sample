#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション生成.
if ($q->request_method eq 'POST'){ # 'POST'の時.

  # CGI::Sessionオブジェクトの作成.
  my $session = CGI::Session->new(); # CGI::Session::newで$session生成.

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Session"); # <html>タグなどの出力.

  # 表示.
  print "username = ".$q->param('username').$q->br;
  print "userpass = ".$q->param('userpass').$q->br;
  print "sessid = ".$session->id;

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # POST以外.(GETなど.)

  # HTTPヘッダの出力.
  print $q->header;

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Session"); # <html>タグなどの出力.

  print "Please POST Request.\n";

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
