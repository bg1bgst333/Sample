#!/usr/bin/perl

# リストで配列を初期化.
@array = (100, 200, 300); # 100, 200, 300という3要素の配列を初期化.

# @arrayの要素を出力.
for ($i = 0; $i < @array; $i++){ # 要素数分繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}

# 先頭に要素を追加.
$var = 50; # $varに50を代入.
print '$var = '."$var\n"; # $varを出力.
unshift(@array, $var); # unshiftで先頭に$varを追加.

# 再び@arrayの要素を出力.
for ($i = 0; $i < @array; $i++){ # 要素数分繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}
