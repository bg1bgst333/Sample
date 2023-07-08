#!/usr/bin/ruby

# クラスTestClassの定義.
class TestClass
  # 指定した値を出力するoutput.
  def output(var)
    puts(var) # putsでvarを出力.
  end
end

# オブジェクトの作成.
obj = TestClass.new # newで作成.
obj.output(10) # obj.outputに10を指定.
