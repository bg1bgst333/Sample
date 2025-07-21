#!/usr/bin/ruby

# 年齢ageが20未満ならそれぞれ"young1", "young2"と表示.
age = 25
unless age >= 20
  puts "young1"
end
age = 10
unless age >= 20
  puts "young2"
end
puts "end"
