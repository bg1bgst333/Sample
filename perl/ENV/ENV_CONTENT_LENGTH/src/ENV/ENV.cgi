#!/usr/bin/perl

# CGIヘッダの出力.
print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
print "\n"; # "\n"を出力.

# 環境変数CONTENT_LENGTHの出力.
print $ENV{'CONTENT_LENGTH'}."\n"; # %ENVのキー'CONTENT_LENGTH'に対する値を出力.
