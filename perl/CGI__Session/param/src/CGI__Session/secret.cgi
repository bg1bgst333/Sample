#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session.

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション復元.
my $session = CGI::Session->load(); # CGISESSIDから復元.

# パラメータ取得.
my $logged_in = $session->param('logged_in');
my $user = $session->param('user');

# 表示.
print $q->header('text/html');
print "logged_in: $logged_in".$q->br;
print "user: $user".$q->br;
