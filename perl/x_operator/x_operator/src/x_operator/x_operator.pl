#!/usr/bin/perl

# 文字列の繰り返し
$str = "ABC" x 3; # "ABCABCABC".
print $str."\n"; # $strを出力.

# 配列要素の繰り返し
@ary = (10, 20) x 2; # (10, 20, 10, 20)
foreach $var (@ary){ # 要素数分繰り返す.
  print $var."\n"; # $varを出力.
}
