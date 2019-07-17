#!/usr/bin/perl

# コマンドライン引数の個数を出力.
$size = @ARGV; # @ARGVのサイズを$sizeに格納.
print '$size = '."$size\n"; # $sizeを出力.

# コマンドライン引数の各要素出力.
for ($i = 0; $i < $size; $i++){ # $size分繰り返す.
  print '$ARGV['."$i".'] = '."$ARGV[$i]\n"; # $ARGV[$i]を出力.
}
