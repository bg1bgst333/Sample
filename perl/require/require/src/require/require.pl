#!/usr/bin/perl

#Cwdモジュールを使う.
#use Cwd; # カレントディレクトリ.
require Cwd; # useをrequireにする.(コンパイル時評価ではなく, 実行時評価になる.)

# カレントディレクトリのパスを取得.
$path = getcwd; # getcwdは文字列リテラル"getcwd"として扱われる.
print "$path\n"; # $pathは"getcwd".
