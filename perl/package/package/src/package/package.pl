#!/usr/bin/perl

# パッケージ宣言なし
$var = 100; # $main::varに100を代入.
print $var."\n"; # $varの値を出力.
print *var."\n"; # 型グロブで自分のパッケージ名を参照.

# パッケージ宣言あり
package PackageA; # パッケージPackageAを宣言.
$var = 200; # $PackageA::varに200を代入.
print $var."\n"; # $varの値を出力.
print *var."\n"; # 型グロブで自分のパッケージ名を参照.

# ブロック
{

  $var = 300; # $PackageA::varに300を代入.
  print $var."\n"; # $varの値を出力.
  print *var."\n"; # 型グロブで自分のパッケージ名を参照.

  # ブロック内のパッケージ宣言
  package PackageB; # パッケージPackageBを宣言.
  $var = 400; # $PackageB::varに400を代入.
  print $var."\n"; # $varの値を出力.
  print *var."\n"; # 型グロブで自分のパッケージ名を参照.

}

# ブロックから抜けた後.
print $var."\n"; # $varの値を出力.
print *var."\n"; # 型グロブで自分のパッケージ名を参照.
