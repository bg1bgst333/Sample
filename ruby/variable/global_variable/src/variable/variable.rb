#!/usr/bin/ruby

# グローバル変数の初期化.
$val = 111
# クラスTestClassの定義.
class TestClass
  # 値の設定setValue.
  def setValue(val)
    $val = val
  end
  # 値の取得getValue.
  def getValue
    return $val
  end
end

# 最初にそのまま出力.
puts $val
# 代入
$val = 222
puts $val
# オブジェクトからのアクセス.
obj = TestClass.new
obj.setValue(333)
ret = obj.getValue()
puts ret
# 最後にそのまま出力.
puts $val
