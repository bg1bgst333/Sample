#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッションの取得..
my $session = CGI::Session->new(undef, $q); # new(dsn, query)で復元.
if ($session){

  # セッションの削除.
  $session->delete();

  # main.cgiに戻る.
  print $q->redirect('main.cgi');

}
else{

  # ヘッダ.
  print $q->header();
  print "no session.".$q->br;

}
