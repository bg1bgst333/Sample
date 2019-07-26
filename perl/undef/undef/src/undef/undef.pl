#!/usr/bin/perl

# 値が定義済みの変数は真(true)となる.
$var = 10; # $varは10とする.
if (defined $var){
  print "true\n";
  print '$var = '.$var."\n";
}
else{
  print "false\n";
}

# undefで値を未定義にできる.
$var = undef; # $varにundefの値を格納.
if (defined $var){
  print "true\n";
  print '$var = '.$var."\n";
}
else{
  print "false\n";
}
