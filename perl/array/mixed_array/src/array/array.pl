#!/usr/bin/perl

# 要素の型を混在できる.
$ary1[0] = 10;
$ary1[1] = "ABC";
$ary1[2] = 1.23;
for ($i = 0; $i < @ary1; $i++){
  print "$ary1[$i]\n";
}

# リストでも混在できる.
@ary2 = (20, "DEF", 4.56);
for ($j = 0; $j < @ary2; $j++){
  print "$ary2[$j]\n";
}
