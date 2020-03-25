# CustomClass
package CustomClass;

# field
our $this; # 自身のオブジェクトを指すthis.
our @arg_list; # 渡された引数リストarg_list.

# new
sub new{
  $this = {}; #thisに無名ハッシュリファレンスをセット.
  shift; # 1つ目はスキップ.
  @arg_list = @_; # 2つ目からは@arg_listに渡す.
  bless $this; # blessで$thisと自身のパッケージを紐づける.
}

# print_arg0
sub print_arg0{
  print '$arg_list[0] = '."$arg_list[0]\n"; # $arg_list[0]を出力.
}

# print_arg1
sub print_arg1{
  print '$arg_list[1] = '."$arg_list[1]\n"; # $arg_list[1]を出力.
}

1;
