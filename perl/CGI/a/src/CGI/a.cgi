#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::a"); # <html>タグなどの出力.

# ハイパーリンクの表示.
print $q->a({-href => 'https://www.yahoo.co.jp/'}, 'Click here!'); # 'https://www.yahoo.co.jp/'へのハイパーリンクを表示.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
