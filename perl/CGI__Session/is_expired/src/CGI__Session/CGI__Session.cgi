#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# ユーザー名とパスワードの取得.
my $username = $q->param('username');
my $userpass = $q->param('userpass');

# 合っているか確認.
if ($username eq 'taro' and $userpass eq 'testpass'){ # ログイン成功.

  # 過去のセッションID取得.
  my $sid = $q->param('sid');
  my $session;
  if ($sid){
    $session = CGI::Session->load($sid);
  }
  else{
    $session = CGI::Session->new();
  }
  $session->expire('+10s');
  $session->param('username', $username);

  # クッキーの期限.
  my $cookie = $q->cookie(-name => 'CGISESSID', -value => $session->id, -expires => '+20s');

  # 表示.
  print $q->header(-cookie => $cookie);
  print $q->start_html("Login OK!");
  print "username: $username".$q->br;
  print $q->a({ href => '/cgi-bin/secret.cgi?sid='.$session->id}, "here");
  print $q->end_html;

}
else{

  # クッキー取得.
  my $cookie_sid = $q->cookie('CGISESSID');
  if (!$cookie_sid){

    # ログインフォーム.
    print $q->header;
    print $q->start_html("Login");
    print $q->start_form(-method => 'POST');
    print "username no sid: ".$q->textfield('username').$q->br;
    print "userpass: ".$q->password_field('userpass').$q->br;
    print $q->submit;
    print $q->end_form;
    print $q->end_html;
    exit;

  }

  # セッション取得.
  my $session = CGI::Session->load($cookie_sid);
  if ($session->is_expired){

    # ログインフォーム.
    print $q->header;
    print $q->start_html("Login");
    print $q->start_form(-method => 'POST');
    print "username expire: ".$q->textfield('username').$q->br;
    print "userpass: ".$q->password_field('userpass').$q->br;
    print $q->submit;
    print $q->end_form;
    print $q->end_html;
    exit;

  }

  # 表示.
  my $cookie = $q->cookie(-name => 'CGISESSID', -value => $session->id, -expires => '+20s');
  print $q->header(-cookie => $cookie);
  print $q->start_html("Login ???");
  $username = $session->param('username');
  print "username: $username".$q->br;
  print $q->a({ href => '/cgi-bin/secret.cgi?sid='.$session->id}, "here");
  print $q->end_html;

}
