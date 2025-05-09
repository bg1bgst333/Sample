#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::textfield"); # <html>タグなどの出力.

# テキストフィールドの出力.
print $q->textfield; # <input>タグのtype=text.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
