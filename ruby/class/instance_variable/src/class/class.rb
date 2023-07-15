#!/usr/bin/ruby

# クラスTestClassの定義.
class TestClass
  # 値の設定setValue.
  def setValue(val)
    @val = val
  end
  # 値の取得getValue.
  def getValue
    return @val
  end
end

# オブジェクトの作成.
obj = TestClass.new() # newで生成.
obj.setValue(123) # obj.setValueで123をセット.
val = obj.getValue() # obj.getValueで取得した値をvalに格納.
puts val # valを出力.
