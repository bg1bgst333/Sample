#!/usr/bin/perl

# パッケージPackageA
{
  package PackageA; # パッケージPackageAを宣言.
  $var = 10;
  $str = "AAA";
}

# パッケージPackageB
{
  package PackageB; # パッケージPackageBを宣言.
  $var = 20;
  $str = "BBB";
}

# mainパッケージ
$var = 30;
$str = "CCC";

# 出力
print $PackageA::var."\n"; # PackageAの$var.
print $PackageA::str."\n"; # PackageAの$str.
print $PackageB::var."\n"; # PackageBの$var.
print $PackageB::str."\n"; # PackageBの$str.
print $main::var."\n"; # mainの$var.
print $main::str."\n"; # mainの$str.

# 代入
$PackageA::str = "XXX"; # PackageAの$strに"XXX"を代入.
$PackageB::var = 100; # PackageBの$varに100を代入.

# 出力
print "\n"; # 改行.
print $PackageA::var."\n"; # PackageAの$var.
print $PackageA::str."\n"; # PackageAの$str.
print $PackageB::var."\n"; # PackageBの$var.
print $PackageB::str."\n"; # PackageBの$str.
print $main::var."\n"; # mainの$var.
print $main::str."\n"; # mainの$str.
