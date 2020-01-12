#!/usr/bin/perl

# 整数値配列の逆順.
@array = (1, 2, 3, 4, 5); # @arrayを1から5までのリストで初期化.
foreach $var (@array){ # @arrayの分繰り返す.
  print $var."\n"; # $varを出力.
}
@new = reverse @array; # @arrayをreverseで逆順にして@newに格納.
foreach $var (@new){ # @newの分繰り返す.
  print $var."\n"; # $varを出力.
}

# 文字列の逆順.
$str = "ABCDE"; # $strを文字列"ABCDE"で初期化.
print $str."\n"; # $strを出力.
$new = reverse $str; # $strを逆順にして, $newに格納.
print $new."\n"; # $newを出力.
