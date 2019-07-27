#!/usr/bin/perl

# qwによるリストで変数を初期化.
($x, $y, $z) = qw/10 20 30/; # qwでスペース区切りで変数を初期化.
print '$x = '."$x".', $y = '."$y".', $z = '."$z\n"; # $x, $y, $zを出力.

# qwによるリストで配列を初期化.
@array = qw/100 200 300/; # qwでスペース区切りで配列を初期化.
for ($i = 0; $i < 3; $i++){ # 3回繰り返す.
  print '$array['.$i.'] = '."$array[$i]\n"; # $array[$i]を出力.
}