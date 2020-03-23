#!/usr/bin/perl

# CustomClassをuseで読み込む.
use CustomClass;

# 無名ハッシュリファレンスをクラスと紐付けてオブジェクトにする.
my $obj = {}; # 無名ハッシュ$obj.
bless $obj, CustomClass; # 組み込み関数blessで$objをCustomClassのオブジェクトとする.
$obj->method1(); # $objからCustomClass::method1を呼び出す.
$obj->method2(); # $objからCustomClass::method2を呼び出す.
$obj->method3("ABC"); # #objからCustomClass::method3を呼び出す.(引数に"ABC"を指定.)
