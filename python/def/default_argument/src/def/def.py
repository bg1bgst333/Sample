#!/usr/bin/python
# coding: utf-8

# 3つのキーワードを出力する関数output_three_keywordの定義.
def output_three_keyword(keyword1="aaa", keyword2="bbb", keyword3="ccc"): # デフォルト引数をそれぞれ"aaa", "bbb", "ccc"とする. 
  # 3つのキーワードを順に出力.
  print "keyword1 = %s, keyword2 = %s, keyword3 = %s" % (keyword1, keyword2, keyword3) # printで3つのキーワードを順に出力.

# 全部省略.
output_three_keyword() # "aaa", "bbb", "ccc".

# 先頭だけ指定.
output_three_keyword("ddd") # "ddd", "bbb", "ccc".

# 先頭から2つ指定.
output_three_keyword("ddd", "eee") # "ddd", "eee", "ccc".

# 全部指定.
output_three_keyword("ddd", "eee", "fff") # "ddd", "eee", "fff".

# キーワード引数を指定すれば, 途中だけ指定も可能.
output_three_keyword(keyword2="xxx") # "aaa", "xxx", "ccc".
