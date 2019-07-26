#!/usr/bin/perl

# 0は偽.
$var1 = 0;
if ($var1){
  print "true\n";
}
else{
  print "false\n";
}

# 空文字列""は偽.
$var2 = "";
if ($var2){
  print "true\n";
}
else{
  print "false\n";
}

# 空リスト()は偽.
@ary = (); # 配列@aryに空リスト.
if (@ary){
  print "true\n";
}
else{
  print "false\n";
}
$var3 = (); # 変数$var3に空リスト.
if ($var3){
  print "true\n";
}
else{
  print "false\n";
}

# 未定義値は空リスト.
$var4 = undef; # $var4にundef.
if ($var4){
  print "true\n";
}
else{
  print "false\n";
}
