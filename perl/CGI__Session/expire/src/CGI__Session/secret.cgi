#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション復元.
my $status;
my $sid = $q->cookie('CGISESSID');
if ($sid eq undef){
  $status = "cookie expired!";
}
$sid = $q->param('sid');
my $session = $sid ? CGI::Session->load($sid) : undef;
if ($session && !$session->is_expired && !$session->is_empty){
  my $username = $session->param('username');
  print $q->header;
  print "username: $username".$q->br;
  print "session id: ".$session->id.$q->br;
  print "status: ".$status.$q->br;
  print $session->is_expired.$q->br;
}
else{
  print $q->redirect("/cgi-bin/CGI__Session.cgi?sid=".$sid);
}
