#!/usr/bin/ruby

# クラスTestClassの定義.
class TestClass
  # 初期化メソッドinitialize(arg).
  def initialize(arg)
    puts("initialize TestClass") # putsで"initialize TestClass"と出力.
    puts(arg) # putsでargを出力.
  end
  # 指定した値を出力するoutput.
  def output(var)
    puts(var) # putsでvarを出力.
  end
end

# オブジェクトの作成.
obj = TestClass.new("ABCDE") # newで"ABCDE"を渡して作成.
obj.output(10) # obj.outputに10を指定.
