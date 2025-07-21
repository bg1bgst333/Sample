#!/usr/bin/ruby

# 1から数えて10を含まないRangeオブジェクトrangeを末尾を含まない範囲演算子を使った範囲式で生成.
range = 1...10
for e in range do
  puts e
end
puts range
