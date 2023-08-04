#!/usr/bin/perl

# 文字列の中にある数値全てを2倍にして置換する.
$str = "2aBc3g_h5klm10x.z12xxx"; # 対象文字列$str.
print $str."\n"; # $strを出力.
$str =~ s/(\d+)/$1 * 2/eg; # 見つかった数値全てを2倍にして置換.
print $str."\n"; # $strを出力.
