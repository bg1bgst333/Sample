#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.

# リダイレクト.
print $q->redirect('https://yahoo.co.jp'); # redirectで'https://yahoo.co.jp'にリダイレクト.
