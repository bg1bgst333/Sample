#!/usr/bin/ruby

# 1から10までのRangeオブジェクトrange1の生成.
range1 = Range.new(1, 10)
for e1 in range1 do
  puts e1
end
puts range1

# 1から数えて10を含まないRangeオブジェクトrange2の生成.
range2 = Range.new(1, 10, true) # 第3引数をtrueにする.
for e2 in range2 do
  puts e2
end
puts range2

