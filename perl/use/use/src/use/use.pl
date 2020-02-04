#!/usr/bin/perl

# Cwdモジュールを使う.
use Cwd; # カレントディレクトリ.

# カレントディレクトリのパスを取得.
$path = getcwd; # getcwdでカレントディレクトリのパスを取得し, $pathに格納.
print "$path\n"; # $pathを出力.
