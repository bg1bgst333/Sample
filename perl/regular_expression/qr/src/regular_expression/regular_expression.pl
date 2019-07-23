#!/usr/bin/perl

# あらかじめ正規表現を保持しておく.
$r = qr/A[bB]C/; # qrで正規表現/A[bB]C/を定義し, $rに格納.

# 標準入力文字列を受け取って, 正規表現に一致するか確認する.
$target = <STDIN>; # STDINから入力文字列を受け取って$targetに格納.
if ($target =~ $r){ # $targetが$rに一致する場合.
  print 'match /A[bB]C/'."\n"; # 'match /A[bB]C/'を出力.
}
else{
  print 'not match /A[bB]C/'."\n"; # 'not match /A[bB]C/'を出力.
}
