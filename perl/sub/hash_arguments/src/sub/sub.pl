#!/usr/bin/perl

use strict; #厳密な文法チェック. 

# サブルーチンの呼び出し.
my %hash1 = ('key1' => 'value1',
             'key2' => 'value2',
             'key3' => 'value3');
hash_arguments_func(%hash1); # %hash1を渡す.
print "\n"; # 改行.
hash_arguments_func(-a=>'aaa',
                    -b=>'bbb',
                    -c=>'ccc'); # 直接渡せる.

# サブルーチンhash_arguments_funcの定義.
sub hash_arguments_func{
  my %hash = @_; # %hashで受け取る.
  foreach my $key (keys(%hash)){
    print "$key = $hash{$key}\n";
  }
}
