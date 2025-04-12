#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション復元.
my $session = CGI::Session->new(undef, $q); # new(dsn, query)で復元.
if ($session){

  # ユーザー名の取得.
  my $username = $session->param('username');

  # ヘッダ.
  print $q->header();

  # セッションIDの確認.
  if ($session->id){
    print "session id: ".$session->id.$q->br;
  }

  # ユーザーがいる.
  if ($username){
    print $username.$q->br;
    print $q->a({-href => 'logout.cgi'}, 'logout');
  }
  else{
    print "no login".$q->br;
  }

}
else{

  # ヘッダ.
  print $q->header();
  print "no session.".$q->br;

}
