#!/usr/bin/perl

# サブルーチンの呼び出し.
$r = add(10, 20); # サブルーチンaddに10と20を渡して, 戻り値を$rに格納.
print 'add(10, 20) = '."$r\n"; # 計算結果として$rを出力.

#サブルーチンaddの定義.
sub add{
  $x = shift(@_); # @_の1つ目をxに格納.
  $y = shift(@_); # @_の2つ目をyに格納.
  $ret = $x + $y; # $x + $yの値を$retに格納.
  return $ret; # returnで$retの値を返す.
}
