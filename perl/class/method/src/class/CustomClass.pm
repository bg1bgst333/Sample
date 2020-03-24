# CustomClass
package CustomClass;

# field
our $this; # 自身のオブジェクトを指すthis.

# attach
sub attach{
  $this = {}; # $thisに無名ハッシュリファレンスをセット.
  bless $this; # blessで$thisと自身のパッケージを紐付ける.(blessの戻り値が完成したオブジェクトで, 最後の行なのでこのまま戻り値として返される.)
}

# method1
sub method1{
  print "method1\n"; # "method1"を出力.
  $arg1 = shift;
  print '$arg1 = '."$arg1\n"; # $arg1を出力.
  $arg2 = shift;
  print '$arg2 = '."$arg2\n"; # $arg2を出力.
}

1;
