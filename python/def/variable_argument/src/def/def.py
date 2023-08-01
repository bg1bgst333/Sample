#!/usr/bin/python
# coding: utf-8

# 引数のキーワードを出力する関数output_argument_keywordの定義.
def output_argument_keyword(keyword1="aaa", *args): # 2つ目以降は可変引数.

  # keyword1を出力.
  print "%s" % (keyword1) # printでkeyword1を出力.

  # argsを出力.
  print args # printでargsを出力.

# 文字列とタプルを渡す.
str1 = "xxx"
pair1 = ("bbb", "ccc")
output_argument_keyword(str1, *pair1)
