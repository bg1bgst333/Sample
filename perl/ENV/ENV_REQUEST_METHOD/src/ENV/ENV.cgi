#!/usr/bin/perl

# CGIヘッダの出力.
print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
print "\n"; # "\n"を出力.

# 環境変数REQUEST_METHODの出力.
print $ENV{'REQUEST_METHOD'}."\n"; # %ENVのキー'REQUEST_METHOD'に対する値を出力.
