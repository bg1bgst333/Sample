#!/usr/bin/perl

# CGIヘッダの出力.
print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
print "\n"; # "\n"を出力.

# 環境変数QUERY_STRINGの出力.
print $ENV{'QUERY_STRING'}."\n"; # %ENVのキー'QUERY_STRING'に対する値を出力.
