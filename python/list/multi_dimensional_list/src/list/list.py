#!/usr/bin/python
# coding: utf-8

# 要素が[[11, 12, 13], [21, 22, 23], [31, 32, 33]]の多次元リスト.
lst1 = [[11, 12, 13], [21, 22, 23], [31, 32, 33]];

# lst1[0]の出力.
print lst1[0]

# lst1[2][1]の出力.
print lst1[2][1] # 32が出力される.

# for-inで全要素を参照.
print "-----"
for sublst in lst1:
  for e in sublst:
    print e
