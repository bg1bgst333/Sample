#!/usr/bin/perl

# CustomClassの読み込み.
use CustomClass;

# CustomClassオブジェクトを取得.
$obj = CustomClass::attach(); # CustomClass::attachで取得したオブジェクトを$objに格納.

# アロー演算子でメソッドを呼び出す.
$obj->method1("ABC"); # $obj->method1に"ABC"を渡す.

# メソッド名の後ろにオブジェクトを指定して呼び出す.
method1 $obj("ABC"); # method1の後に$objを置いて, そのあと括弧で"ABC"を指定.

# メソッド名の後ろにクラス名を指定して呼び出す.(クラスメソッドまたはスタティックメソッド.)
method1 CustomClass("ABC"); # method1の後にCustomClassを置いて, そのあと括弧で"ABC"を指定.
