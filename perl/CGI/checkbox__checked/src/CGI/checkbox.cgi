#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::checkbox(-checked)"); # <html>タグなどの出力.

# チェックボックスの出力.
print $q->checkbox(-checked => 'checked'); # <input>タグのtype=checkboxであらかじめチェックを付ける.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
