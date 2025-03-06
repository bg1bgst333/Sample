#!/usr/bin/perl

use strict; # 厳密な文法チェック.
use CGI; # CGI
use CGI::Carp; # CGI::Carp

# CGIオブジェクトの作成.
my $q = CGI->new; # CGI::newでCGIオブジェクトを生成し, $qに格納.
  
# HTTPヘッダの出力.
print $q->header;

# HTMLヘッダの出力.
print $q->start_html("CGI::Carp"); # <html>タグなどの出力.

# エラー発生.
croak "CGI::Carp!"; # croakで"CGI::Carp!"と出力. 

# HTMLフッタの出力.
print $q->end_html; # </html>タグなどの出力.
