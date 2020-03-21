my $var1 = 1; # $var1を1で初期化.
print '$var1 = '."$var1\n"; # $var1を出力.
{
  print '$var1 = '."$var1\n"; # $var1を出力.
  $var1 = 2; # $var1に2を代入.
  print '$var1 = '."$var1\n"; # $var1を出力.
  {
    $var1 = 3; # $var1に3を代入.
    print '$var1 = '."$var1\n"; # $var1を出力.
    my $var1 = 4; # $var1に4を代入.
    print '$var1 = '."$var1\n"; # $var1を出力.
  }
  print '$var1 = '."$var1\n"; # $var1を出力.
}
print '$var1 = '."$var1\n"; # $var1を出力.
