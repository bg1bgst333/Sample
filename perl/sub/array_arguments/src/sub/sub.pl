#!/usr/bin/perl

use strict; #厳密な文法チェック. 

# サブルーチンの呼び出し.
my @ary1 = (10, 20, 30);
array_arguments_func(@ary1); # @ary1を渡す.

# サブルーチンarray_arguments_funcの定義.
sub array_arguments_func{
  my @ary = @_; # @aryで受け取る.
  foreach my $val (@ary){
    print $val."\n";
  }
}
