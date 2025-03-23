#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::b"); # <html>タグなどの出力.

# 3行の段落(1行目は太字.)を表示.
print $q->p($q->b('Line 1 is Bold Text').$q->br.
            'Line 2'.$q->br.
            'Line 3'
            ); # <p>タグと<br>タグと<b>タグで3行の段落.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
