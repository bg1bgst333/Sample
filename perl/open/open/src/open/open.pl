#!/usr/bin/perl

# ファイルのオープンに失敗した場合, falseが返る.
$ret = open(IN, "<", "test.txt"); # "test.txt"は存在しないのでfalseが返る.
if ($ret){
  print '$ret is true'."\n";
}
else{
  print '$ret is false'."\n";
}
