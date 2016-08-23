// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <cmath> // C数学関数

// 独自のヘッダ
#include "square_root.h" // クラスclass_square_root

// class_square_rootのメンバの定義
// コンストラクタclass_square_root(x, y)
class_square_root::class_square_root(double x, double y){

  // 引数をメンバにセット.
  x_ = x; // x_にxをセット.
  y_ = y; // y_にyをセット.

}

// doubleを戻り値とするユーザ定義演算子.
class_square_root::operator double(){

  // 平方根を返す.
  return sqrt(pow(x_, 2.0) + pow(y_, 2.0)); // x_の2乗 + y_の2乗の平方根を返す.

}
