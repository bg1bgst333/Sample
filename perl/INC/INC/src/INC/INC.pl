#!/usr/bin/perl

# モジュールの検索パスの一覧を出力.
for $path (@INC){ # @INCから要素を取り出し, $pathに格納.
  print "$path\n"; # $pathを出力.
}
