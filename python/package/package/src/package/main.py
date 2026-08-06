#!/usr/bin/python
# coding: utf-8

# custom_pkgパッケージの各モジュールのインポート.
import custom_pkg.custom_mod1
import custom_pkg.custom_mod2

# addとsubの呼び出し.
print(custom_pkg.custom_mod1.add(10, 20))
print(custom_pkg.custom_mod2.sub(10, 20))
