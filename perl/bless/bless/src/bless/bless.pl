#!/usr/bin/perl

# CustomClassの読み込み.
use CustomClass;

# CustomClassオブジェクトを取得.
$obj = CustomClass::attach(); # CustomClass::attachで取得したオブジェクトを$objに格納.

# CustomClassオブジェクトのmethod1を呼ぶ.
$obj->method1(); # $obj->method1を呼ぶ.
