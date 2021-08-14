#!/usr/bin/perl

use strict; # 厳密な文法チェック.

# ファイルtest.txtのファイルサイズを取得する.
my $filesize = -s "test.txt"; # "test.txt"のサイズを取得し, $filesizeに格納.
print '$filesize = '.$filesize."\n"; # $filesizeを出力.
