#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# パラメータ取得.
my $sid = $q->param('CGISESSID');

# セッション復元.
my $session = CGI::Session->load(undef, $sid); # loadで復元.

# パラメータ取得.
my $username = $session->param('username') || '(empty)';

# 表示.
print $q->header();
print "<html><body>";
print "<p>username: ".$username."</p>";
print "</body></html>";
