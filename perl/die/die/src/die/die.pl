#!/usr/bin/perl

# ファイルのオープンに失敗した場合, dieでエラーメッセージ.
$ret = open(IN, "<", "test.txt") || die "open error!!"; # "test.txt"は存在しないのでエラーメッセージが出力される.
