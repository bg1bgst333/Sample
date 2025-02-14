#!/usr/bin/python
# coding: utf-8

# インポート
import custom_mod

# ドキュメントストリングの表示.
print custom_mod.__doc__

# custom_funcを呼ぶ.
num = custom_mod.custom_func(10, 20)

# numの出力.
print "num = %d" % num
