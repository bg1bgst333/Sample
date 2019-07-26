#!/usr/bin/perl

# 値が未定義の変数は偽(false)となる.
if (defined $var1){
  print "true\n";
}
else{
  print "false\n";
}

# 値が定義済みの変数は真(true)となる.
$var2 = 10; # $var2は10とする.
if (defined $var2){
  print "true\n";
  print '$var2 = '.$var2."\n";
}
else{
  print "false\n";
}
