#!/usr/bin/ruby

# クラスTestClassの定義.
class TestClass
  # 値の設定setValue.
  def setValue(val)
    @@val = val
  end
  # 値の取得getValue.
  def getValue
    return @@val
  end
end

# obj1の作成.
obj1 = TestClass.new() # newでobj1を生成.
obj1.setValue(123) # obj1.setValueで123をセット.
val1 = obj1.getValue() # obj1.getValueで取得した値をval1に格納.
puts val1 # val1を出力.
# obj2の作成.
obj2 = TestClass.new() # newでobj2を生成.
val2 = obj2.getValue() # obj2.getValueで取得した値をval2に格納.
puts val2 # val2を出力.
