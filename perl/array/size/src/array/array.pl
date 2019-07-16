#!/usr/bin/perl

# リストで配列を初期化.
@array = (100, 200, 300); # 100, 200, 300という3要素の配列を初期化.
$size = @array; # @arrayの要素数を$sizeに格納.
print '$size = '."$size\n"; # $sizeを出力.
for ($i = 0; $i < $size; $i++){ # $size分繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}
