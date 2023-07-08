#!/usr/bin/ruby

# ローカル変数var1の値を出力するoutputVar1.
def outputVar1
  var1 = 10; # var1を10で初期化.
  puts(var1); # putsでvar1を出力. 
end

# outputVar1を呼ぶ.
outputVar1
puts(var1) # ここでvar1を使おうとしてもスコープ外.
