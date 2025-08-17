#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::start_form(-action,-enctype)"); # <html>タグなどの出力.

# HTMLフォームの出力.
print $q->start_form(-action => 'action.cgi', -enctype => 'application/x-www-form-urlencoded'); # <form>タグの出力.
print "\n"; # 改行の出力.
print "<input name=\"key1\" value=\"value1\">\n"; # key1
print "<input name=\"key2\" value=\"value2\">\n"; # key2
print "<input type=\"submit\" value=\"submit\">\n"; # submit
print $q->end_form; # </form>タグの出力.

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
