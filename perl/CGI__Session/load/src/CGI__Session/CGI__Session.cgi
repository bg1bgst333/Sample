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

  # クッキー作成.
  my $cookie = $q->cookie(-name => 'CGISESSID', -value => $session->id, -expires => '+5m');

  # HTTPヘッダーの出力.
  print $q->header(-cookie => $cookie);

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Session::load"); # <html>タグなどの出力.

  # 表示.
  print "username = ".$q->param('username').$q->br;
  print "userpass = ".$q->param('userpass').$q->br;
  print "CGISESSID = ".$session->id.$q->br;
  print $q->a({-href => '/cgi-bin/CGI__Session.cgi'}, 'here').$q->br;

  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
else{ # POST以外.(GETなど.)

  # CGI::Sessionオブジェクトのロード.
  my $session = CGI::Session->load();

  # 期限切れクッキー作成.
  my $expired = $q->cookie(-name => 'CGISESSID', -value => $session->id, -expires => '-1d');

  # HTTPヘッダーの出力.
  print $q->header(-cookie => $expired);

  # HTMLヘッダの出力.
  print $q->start_html("CGI::Session::load"); # <html>タグなどの出力.

  # セッションIDの表示.
  if ($session){
    print "load CGISESSID: ".$session->id.$q->br;
  }
  
  # HTMLフッタの出力.
  print $q->end_html; # </html>タグなどの出力.

}
