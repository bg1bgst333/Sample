#!/usr/bin/perl

# そのままの順の長さ2の16進数文字列を, 16進数バイナリに変換.
$packed = pack("H2", "1a"); # packで"1a"をそのままの16進数0x1aにする.

# ファイルを開く.
open $fh, '>', "packed.bin"; # openで"packed.bin"を開く.

# $fhをバイナリモードに.
binmode $fh; # binmodeで$fhをバイナリモードに.

# バイナリ書き込み.
print $fh $packed; # printで$fhに$packedを書き込み.

# ファイルを閉じる.
close $fh; # closeで$fhを閉じる.
