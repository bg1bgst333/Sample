#!/usr/bin/perl

# 3つの整数を連結し, 32ビット符号付き整数バイナリに変換.
$packed = pack("l3", 1, 2, 3); # packで1, 2, 3を連結して, 32ビット符号付き整数バイナリを作る.

# ファイルを開く.
open $fh, '>', "packed.bin"; # openで"packed.bin"を開く.

# $fhをバイナリモードに.
binmode $fh; # binmodeで$fhをバイナリモードに.

# バイナリ書き込み.
print $fh $packed; # printで$fhに$packedを書き込み.

# ファイルを閉じる.
close $fh; # closeで$fhを閉じる.
