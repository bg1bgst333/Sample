#!/usr/bin/perl

# ヒアドキュメントで複数行の文字列を変数に格納.
$text = <<END; # ENDの前まで格納する.
ABCDE
FGHIJ
KLMNO
PQRST
UVWXY
Z
END

# $textの出力.
print "$text" # $textを出力.(改行は不要.)
