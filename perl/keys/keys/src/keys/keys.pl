#!/usr/bin/perl

use strict; #厳密な文法チェック.

# ハッシュの初期化.
my %hash1 = ('key1' => 'value1',
             'key2' => 'value2',
             'key3' => 'value3');

# キー配列の取得.
my @keys1 = keys(%hash1);
foreach my $val (@keys1){
  print $val."\n";
}
