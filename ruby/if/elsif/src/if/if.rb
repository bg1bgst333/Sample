#!/usr/bin/ruby

# 年齢の範囲ごとに当てはまる呼称を出力.
age = 15 
if age >= 20
  puts "adult"
elsif age >= 18
  puts "youth"
elsif age >= 13
  puts "teen"
else
  puts "child"
end
