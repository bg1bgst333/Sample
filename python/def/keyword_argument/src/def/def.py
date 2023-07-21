#!/usr/bin/python
# coding: utf-8

# 3つのキーワードを出力する関数output_three_keywordの定義.
def output_three_keyword(keyword1, keyword2, keyword3):
  # 3つのキーワードを順に出力.
  print "keyword1 = %s, keyword2 = %s, keyword3 = %s" % (keyword1, keyword2, keyword3) # printで3つのキーワードを順に出力.

# output_three_keyword()を呼んで3つのキーワード出力
output_three_keyword("aaa", "bbb", "ccc") # output_three_keywordに"aaa", "bbb", "ccc"を渡す.

# キーワード引数でどの引数に渡すか指定できる.
output_three_keyword(keyword3="ccc", keyword2="bbb", keyword1="aaa") # こうやって逆順に指定することもできる.
