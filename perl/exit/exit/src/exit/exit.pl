#!/usr/bin/perl

$i = <STDIN>; # 標準入力から読み込んだ数値を$iに格納.
chomp $i; # chompで末尾の改行を取り除く.

if ($i <= 0){ # 0以下なら.
  print '$i <= 0'."\n"; # '$i <= 0'と出力.
  exit 10; # exitで処理を中止し, 10を返す.
}

print '$i = '.$i."\n"; # $iを出力.
