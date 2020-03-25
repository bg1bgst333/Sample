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

# method
sub method{
  print "DerivedClass::method 1\n";
  $this->SUPER::method(); # 親クラスのmethodを呼ぶ.
  print "DerivedClass::method 2\n";
}

1;
