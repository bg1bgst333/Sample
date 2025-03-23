#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::table"); # <html>タグなどの出力.

# テーブルの表示.
print $q->table({border => 1},
                $q->Tr($q->td('A1'))
                ); # 'A1'だけのテーブルを表示.
 
# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
