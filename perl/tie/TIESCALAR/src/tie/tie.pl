#!/usr/bin/perl

use strict;
use warnings;

# tieで変数とクラスを結び付ける.
tie my $scalar, 'TiedScalar', 100; # 初期値100で初期化.

# 値の取得
print $scalar."\n";

# 'TiedScalar'の定義
package TiedScalar;

# 初期化
sub TIESCALAR{
  my ($class, $initial) = @_; # 第2引数で初期値を受け取る.
  return bless \$initial, $class;
}

# 取得
sub FETCH{
  my $self = shift;
  print "[FETCH] ";
  return $$self;
}

# 格納
sub STORE{
  my ($self, $value) = @_;
  print "[STORE] ";
  $$self = $value;
}
