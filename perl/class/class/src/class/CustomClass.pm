# CustomClass(クラスの正体はモジュール.)
package CustomClass;

# method1
sub method1{
  print "method1\n";
}

# method2
sub method2{
  print "method2\n";
  $arg1 = shift;
  print '$arg1 = '."$arg1\n"; # $arg1を出力.
}

# method3
sub method3{
  print "method3\n";
  $arg1 = shift;
  print '$arg1 = '."$arg1\n"; # $arg1を出力.
  $arg2 = shift;
  print '$arg2 = '."$arg2\n"; # $arg2を出力.
}

1;
