#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Session; # Session

# 標準出力のバッファ無効化.(これやらないとsleep中に表示なんてできない.)
BEGIN{ $| = 1; }

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# セッション復元.
my $session = CGI::Session->new(undef, $q); # newで生成.

# パラメータをセット.
$session->param('username', 'taro'); # paramで'username'に'taro'をセット.

# セッションIDを取得.
my $sid = $session->id;

# 表示.
print $q->header();
print "<html><body>";
print "<p>session id: $sid</p>";
print "<p>sleep...</p>";
print "<p><a href='read_session.cgi?CGISESSID=".$sid."' target='_blank'>check</a></p>";
print "</body></html>";

# 10秒休止.
sleep(10);

# フラッシュ.
$session->flush();

