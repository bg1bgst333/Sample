#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション復元.
my $sid = $q->cookie('CGISESSID');
my $session = CGI::Session->load(undef, $sid); # loadで復元.
if ($session){

  my $msg;
  # セッションが空.
  if ($session->is_empty){
    print $q->redirect('CGI__Session.cgi');
  }

  # セッション期限切れ.
  if ($session->is_expired){
    print $q->redirect('CGI__Session.cgi');
  }

  # ユーザー名の取得.
  my $username = $session->param('username');

  # ヘッダ.
  print $q->header();

  # セッションIDの確認.
  if ($session->id){
    print "sid: ".$sid.$q->br;
    print "session id: ".$session->id.$q->br;
  }

  # ユーザーがいる.
  if ($username){
    print $username.$q->br;
    print $q->a({-href => 'logout.cgi'}, 'logout');
  }
  else{
    print "no login".$msg.$q->br;
  }

}
else{

  # ヘッダ.
  print $q->header();
  print "no session.".$q->br;

}
