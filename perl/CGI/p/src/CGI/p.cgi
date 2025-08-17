#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::p"); # <html>タグなどの出力.

# 3行の段落を3つ表示.
print $q->p('Line 1'.$q->br.
            'Line 2'.$q->br.
            'Line 3'
            ); # <p>タグと<br>タグで3行の段落.
print $q->p('Line 4'.$q->br.
            'Line 5'.$q->br.
            'Line 6'
            ); # <p>タグと<br>タグで3行の段落.
print $q->p('Line 7'.$q->br.
            'Line 8'.$q->br.
            'Line 9'
            ); # <p>タグと<br>タグで3行の段落.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
