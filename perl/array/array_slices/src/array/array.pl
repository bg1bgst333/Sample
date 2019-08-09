#!/usr/bin/perl

# 複数の要素から値を取り出す配列スライス.
@ary1 = ("ABC", "DEF", "GHI", "JKL", "MNO"); # リストで@ary1の初期化.
@ary2 = @ary1[0, 2..4]; # @ary1の0番目と2から4番目までを取り出し@ary2に代入.
foreach $var (@ary2){ # foreachで@ary2の取り出し.
  print '$var = '."$var\n"; # $varの出力.
}

# 複数の要素に値を入れる配列スライス.
@ary3[0, 4] = ("AAA", "EEE"); # リストで指定したそれぞれの値を@ary3の0番目と4番目に格納.
foreach $var (@ary3){ # foreachで@ary3の取り出し.
  print '$var = '."$var\n"; # $varの出力.
}
