#!/usr/bin/perl

# DerivedClassを読み込む.
use DerivedClass;

# オブジェクト生成.
$obj = new DerivedClass(); # DerivedClassオブジェクトを生成.

# derived_method呼び出し.
$obj->derived_method(); # $obj->devied_methodで呼ぶ.

# base_method呼び出し.
$obj->base_method(); # $obj->base_methodで呼ぶ.
