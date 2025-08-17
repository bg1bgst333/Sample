#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTML(HTTPボディ)の出力.
print $q->start_html; # start_htmlは, <html>タグから始まり, title, そしてbodyの開始タグの部分まで用意してくれる.
print "<a href=\"http://bgstation0.com/\">B.G-STATION</a>\n"; # "<a href="http://bgstation0.com/">B.G-STATION</a>"と出力.
print "</body>\n"; # "</body>"と出力.
print "</html>\n"; # "</html>"と出力.
