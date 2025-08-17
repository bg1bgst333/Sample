#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# CGIヘッダの出力.
print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
print "\n"; # "\n"を出力.

# リクエストの読み込み.
my $buf; # バッファ.
read(STDIN, $buf, $ENV{'CONTENT_LENGTH'});
print $buf
