#!/usr/bin/perl

# CGIパラメータサイズの取得.
$size = @ARGV; # @ARGVのサイズを$sizeに格納.

# CGIヘッダの出力.
print "Content-type: text/plain\n"; # "Content-type: text/plain\n"を出力.
print "\n"; # "\n"を出力.

# CGIパラメータサイズの出力.
print "\$size = $size\n"; #sizeを出力.

# CGIパラメータ要素の取得及び出力.
for ($i = 0; $i < $size; $i++){ # $size分繰り返す.
  print '$ARGV['."$i".'] = '."$ARGV[$i]\n"; # $ARGV[$i]を出力.
}
