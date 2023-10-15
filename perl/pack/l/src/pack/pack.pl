#!/usr/bin/perl

# 4つの整数を連結し, 32ビット符号付き整数バイナリに変換.
$packed = pack("l4", 1, 2, 3, 4); # packで1, 2, 3, 4を連結して, 32ビット符号付き整数バイナリを作る.

# ファイルを開く.
open $fh, '>', "packed.bin"; # openで"packed.bin"を開く.

# $fhをバイナリモードに.
binmode $fh; # binmodeで$fhをバイナリモードに.

# バイナリ書き込み.
print $fh $packed; # printで$fhに$packedを書き込み.

# ファイルを閉じる.
close $fh; # closeで$fhを閉じる.
