#!/usr/bin/perl

# 文字列変数
$str = "ABC"; # $strに"ABC"を格納.

# 文字列変数を含めた文字列の出力.
#print "abc$strXYZ\n"; # 区切りなく文字列変数を展開させようとする.
print "abc${str}XYZ\n"; # $のあとに"{"と"}"で区切って中に変数名を書く.
