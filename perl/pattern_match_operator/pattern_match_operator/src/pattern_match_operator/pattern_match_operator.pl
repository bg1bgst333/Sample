#!/usr/bin/perl

# 標準入力文字列を受け取って, 正規表現に一致するか確認する.
$target = <STDIN>; # STDINから入力文字列を受け取って$targetに格納.
if ($target =~ /A[bB]C/){ # "AbC"または"ABC"に一致する場合.
  print 'match /A[bB]C/'."\n"; # 'match /A[bB]C/'を出力.
}
else{
  print 'not match /A[bB]C/'."\n"; # 'not match /A[bB]C/'を出力.
}
