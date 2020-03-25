#!/usr/bin/perl

# CustomClassの読み込み.
use CustomClass;

# CustomClassオブジェクトの生成.
my $obj = new CustomClass("ABC", "XYZ"); # newでCustomClassを生成.(コンストラクタに"ABC", "XYZ"を渡して, $objをもらう.)

# 引数出力
$obj->print_arg0();
$obj->print_arg1();
