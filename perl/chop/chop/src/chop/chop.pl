#!/usr/bin/perl

# chompで末尾の改行を取り除く.
$str = "ABCD"; # $strを"ABCD"で初期化.
chomp $str; # 末尾が改行ではないので取り除かない.
print $str."\n"; # $strをprintで出力.

# chopで最後の文字を取り除く.
chop $str; # 最後の文字が取り除かれる.
print $str."\n"; # $strをprintで出力.
