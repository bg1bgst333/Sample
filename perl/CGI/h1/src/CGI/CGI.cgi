#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTML(HTTPボディ)の出力.
print $q->start_html('CGI::h1'); # 'CGI::h1'をタイトルとする.
print $q->h1; # h1タグを入れる.
print "\n"; # 改行.
print "<a href=\"http://bgstation0.com/\">B.G-STATION</a>"; # "<a href="http://bgstation0.com/">B.G-STATION</a>"と出力.
print $q->end_html; # end_htmlは, bodyの終了タグ, htmlの終了タグを用意してくれる.
