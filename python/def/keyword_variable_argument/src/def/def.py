#!/usr/bin/python
# coding: utf-8

# 引数のキーワードを出力する関数output_argument_keywordの定義.
def output_argument_keyword(*args, **keyargs): # 普通の可変引数がある程度終わったら, 次はキーワード可変引数.

  # argsを出力.
  print args # printでargsを出力.

  # keyargsを出力.
  print keyargs # printでkeyargsを出力.

# 普通の渡し方とキーワード付きの渡し方.
output_argument_keyword("aaa", "bbb", key1="ccc", key2="ddd") # "aaa", "bbb", key1="ccc", key2="ddd"を渡す.
