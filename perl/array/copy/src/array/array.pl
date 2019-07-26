#!/usr/bin/perl

# 配列のコピー
@ary1 = (10, 20, 30);
@ary2 = @ary1; # @ary1を@ary2にコピー.
for ($i = 0; $i < @ary1; $i++){
  print $ary1[$i]."\n";
}
for ($i = 0; $i < @ary2; $i++){
  print $ary2[$i]."\n";
}
$ary1[0] = 40; # $ary1[0]だけ変更.
$ary2[2] = 50; # $ary2[2]だけ変更.
for ($i = 0; $i < @ary1; $i++){
  print $ary1[$i]."\n";
}
for ($i = 0; $i < @ary2; $i++){
  print $ary2[$i]."\n";
}
