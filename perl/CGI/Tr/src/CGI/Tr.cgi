#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::Tr"); # <html>タグなどの出力.

# テーブルの表示.
print $q->table({border => 1},
                $q->Tr($q->td('A1'), $q->td('B1'), $q->td('C1')),
                $q->Tr($q->td('A2'), $q->td('B2'), $q->td('C2')),
                $q->Tr($q->td('A3'), $q->td('B3'), $q->td('C3'))
                );
                # 'A1', 'B1', 'C1',
                # 'A2', 'B2', 'C2',
                # 'A3', 'B3', 'C3'のテーブルを表示.
 
# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
