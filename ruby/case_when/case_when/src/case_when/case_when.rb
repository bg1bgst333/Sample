#!/usr/bin/ruby

# 番号が1なら"One", 2なら"Two", 3なら"Three", それ以外は"Other"と表示.
num = 3
case num
when 1
  puts "One"
when 2
  puts "Two"
when 3
  puts "Three"
else
  puts "Other"
end

# 点数が100-90は"Excellent", 89-70は"Good", 69-50は"Normal", それ以外は"Bad"と表示.
score = 80
case score
when 90..100
  puts "Excellent"
when 70..89
  puts "Good"
when 50..69
  puts "Normal"
else
  puts "Bad"
end
