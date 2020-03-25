# DerivedClass
package DerivedClass;

# use
use BaseClass;

# 継承
our @ISA = qw/BaseClass/; # BaseClassを継承.
our $this; # オブジェクト自身.

# new
sub new{
  $this = {}; # 無名ハッシュリファレンス.
  bless $this; # blessでパッケージと紐付ける.
}

# derived_method
sub derived_method{
  print "derived_method\n"; # "derived_method"を出力.
}

1;
