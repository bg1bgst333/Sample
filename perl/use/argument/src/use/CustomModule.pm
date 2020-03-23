# CustomModule
package CustomModule;

# BEGIN
BEGIN{
  print "This is BEGIN.\n";
}

# import
sub import{
  print "This is import.\n";
  $arg1 = shift; # パッケージ名
  $arg2 = shift; # 引数
  print '$arg1 = '."$arg1\n";
  print '$arg2 = '."$arg2\n";
}

1; # これがないとエラーメッセージ.
