#!/usr/bin/ruby

# キーが"a", "b", "c"となるハッシュ.
hash1 = {"a" => "aaa", "b" => "bbb", "c" => "ccc"} # 値は"aaa", "bbb", "ccc".

# 値配列の取得.
hash1_values = hash1.values # hash1.valuesで値配列を取得し, hash1_valuesに格納.

# 値配列の出力.
puts hash1_values # putsでhash1_valuesを出力.
