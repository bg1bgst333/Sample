#!/usr/bin/perl

# リストで配列を初期化.
@array = (100, 200, 300); # 100, 200, 300という3要素の配列を初期化.

# @arrayの要素を出力.
for ($i = 0; $i < @array; $i++){ # 要素数分繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}

# shiftで先頭の要素を取り出す.
$str = shift(@array); # @arrayからshiftで先頭を取り出して$strに格納.
print '$str = '."$str\n"; # $strを出力.

# 再び@arrayの要素を出力.
for ($i = 0; $i < @array; $i++){ # 要素数分繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}
