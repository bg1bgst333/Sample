#!/usr/bin/perl

# 無名サブルーチンの生成
$anonymous_sub = sub {
  $ret = $_[0] + $_[1]; # 0番目と1番目を足して$retに代入.
  return $ret; # $retを返す.
};

# 無名サブルーチンの呼び出し.
$result = &$anonymous_sub(10, 20); # anonymous_subの参照先に10と20を渡して, 戻り値を取得し, $resultに格納.
print $result."\n"; # $resultを出力.
