#!/usr/bin/python
# coding: utf-8

# インポート
import custom_mod1
import custom_mod2

# custom_mod1のcustom_funcを呼ぶ.
num1 = custom_mod1.custom_func(10, 20)
# cusrom_mod2のcustom_funcを呼ぶ.
num2 = custom_mod2.custom_func(30, 20)

# num1の出力.
print "num1 = %d" % num1

# num2の出力.
print "num2 = %d" % num2
