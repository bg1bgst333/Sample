#!/usr/bin/perl

# $usersの各プロファイルを定義.
$users = {
  'user1' => {
    'id' => 1,
    'name' => 'Taro',
    'age' => 20,
    'address' => 'Tokyo'
  },
  'user2' => {
    'id' => 2,
    'name' => 'Jiro',
    'age' => 18,
    'address' => 'Osaka'
  },
  'user3' => {
    'id' => 3,
    'name' => 'Saburo',
    'age' => 16,
    'address' => 'Nagoya'
  }
};

# 各プロファイルの出力.
@array = ('user1', 'user2', 'user3');
foreach $var (@array){
  print $users->{$var}{'id'}."\n";
  print $users->{$var}{'name'}."\n";
  print $users->{$var}{'age'}."\n";
  print $users->{$var}{'address'}."\n";
  print "\n";
}
