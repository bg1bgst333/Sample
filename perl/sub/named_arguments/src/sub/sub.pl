#!/usr/bin/perl

use strict; #厳密な文法チェック.

# サブルーチンの呼び出し.
named_arguments_func(-value1 => 'XXX', -value3 => 'ZZZ'); # -value1と-value3に新たに値を指定する.

# サブルーチンnamed_arguments_funcの定義.
sub named_arguments_func{
  my %default_arguments = (-value1 => 'AAA',
                           -value2 => 'BBB',
                           -value3 => 'CCC'); # 引数のデフォルト値はこうなっている.
  my %arguments = (%default_arguments, @_); # 実際の引数はデフォルトのキーを持つハッシュと渡されたハッシュで構成される.
  foreach my $key (keys(%arguments)){
    print "$key = $arguments{$key}\n";
  }
}
