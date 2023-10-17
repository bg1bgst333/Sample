#!/usr/bin/ruby

# 複数の変数に, 複数の値を代入.
a, b, c = 1, 2, 3 # a = 1, b = 2, c = 3
print a, ", ", b, ", ", c, "\n" # printでaとbとcを出力.

# 変数が余っている場合, nilが入る.
a, b, c = 1, 2 # a = 1, b = 2, c = nil
print a, ", ", b, ", ", c, "\n" # printでaとbとcを出力.

# 配列の各要素を入れることもできる.
a, b, c = [1, 2, 3] # a = 1, b = 2, c = 3
print a, ", ", b, ", ", c, "\n" # printでaとbとcを出力.

# 値が余っている場合は, 切り捨てられる.
a, b = [1, 2, 3] # a = 1, b = 2
print a, ", ", b, "\n" # printでaとbを出力.

# 変数が1つの場合は, 配列になる.
a = 1, 2, 3 # a = [1, 2, 3]
print a, "\n" # printでaを出力.
