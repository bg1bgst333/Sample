#!/usr/bin/perl

# サブルーチンの呼び出し.
printStr("ABCDE"); # サブルーチンprintStrに"ABCDE"を渡す.

#サブルーチンprintStrの定義.
sub printStr{
  $arg = shift(@_); # @_に引数が入ってるのでshiftで取り出して$argに格納.
  print "$arg\n"; # $argを出力.
}
