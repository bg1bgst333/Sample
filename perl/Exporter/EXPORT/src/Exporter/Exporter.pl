#!/usr/bin/perl

# CustomModuleをuseで読み込む.
use CustomModule;

# CustomModuleの公開メソッドを呼ぶ.
public_method_1(); # public_method_1を呼ぶ.

# CustomModuleの非公開メソッドは直接呼べない.
#private_method(); # private_methodは見えない.
CustomModule::private_method(); # パッケージ名を付けると呼べる.

# CustomModuleの公開メソッド経由で非公開メソッドを呼ぶ.
public_method_2(); # public_method_2を呼ぶ.
