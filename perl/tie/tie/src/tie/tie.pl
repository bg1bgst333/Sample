#!/usr/bin/perl

use strict;
use warnings;

# tieで変数とクラスを結び付ける.
tie my $scalar, 'TiedScalar';

# 値の格納
$scalar = "ABCDE";

# 値の取得
print $scalar."\n";

# 'TiedScalar'の定義
package TiedScalar;

# 初期化
sub TIESCALAR{
  my $class = shift;
  my $value = "";
  return bless \$value, $class;
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
