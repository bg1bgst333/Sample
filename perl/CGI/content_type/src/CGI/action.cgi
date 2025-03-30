#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTML(HTTPボディ)の出力.
print $q->start_html('CGI::content_type'); # タイトルは'CGI::content_type'.
print $ENV{'QUERY_STRING'}.$q->br; # $ENV{'QUERY_STRING'}の表示.
print $q->query_string.$q->br; # $q->query_stringの表示.
print $ENV{'CONTENT_TYPE'}.$q->br; #$ENV{'CONTENT_TYPE'}の表示.
print $q->content_type.$q->br; # $q->content_typeの表示.

print $q->end_html; # フッター.
