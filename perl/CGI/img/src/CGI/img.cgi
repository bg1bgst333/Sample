#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::img"); # <html>タグなどの出力.

# 画像の表示.
print $q->img({-src => '/images/image.jpg'}); # '/images/image.jpg'の表示.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
