#!/usr/bin/perl

# 配列の初期化.
@array = (100, 200, 300, 400, 500); # 100から500まで.
@new = (350, 375, 450); # 350, 375, 450という3要素の配列を初期化.

# 指定の位置の要素を置換.
@old = splice @array, 2, 2, @new; # 2番目からの2つの要素を@newに置き換え, 元の配列は@oldに返る.

# @oldの中身を出力.
print '@old'."\n";
foreach $var (@old){
  print $var."\n";
}

# 改行
print "\n";

# @arrayの中身を出力.
print '@array'."\n";
foreach $var (@array){
  print $var."\n";
}
