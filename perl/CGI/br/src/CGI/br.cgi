#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::br"); # <html>タグなどの出力.

# 文字列の出力.
print "ABCDE\n"; # "ABCDE"を出力.

# <br />タグの出力.
print $q->br."\n"; # <br />タグの出力.

# 文字列の出力.
print "FGHIJ\n"; # "FGHIJ"を出力.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
