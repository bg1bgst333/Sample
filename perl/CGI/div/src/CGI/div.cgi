#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::div"); # <html>タグなどの出力.

# 3つのdivタグを表示.
print $q->div({-align => 'center'}, 'Line 1'.$q->br.
              'Line 2'.$q->br.
              'Line 3'
             ); # <div>タグで中央に3行表示.
print $q->div({-align => 'left'}, 'Line 1'.$q->br.
              'Line 2'.$q->br.
              'Line 3'
             ); # <divタグで左に3行表示.
print $q->div({-align => 'right'}, 'Line 1'.$q->br.
              'Line 2'.$q->br.
              'Line 3'
             ); # <div>タグで右に3行表示.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
