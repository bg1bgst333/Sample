// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test

// class_testのメンバの定義
// メンバ関数get_i
int class_test::get_i() const{

  // 値を返す.
  //i_ = -1; // i_に-1を代入してみる.(これはできない.)
  return i_; // i_を返す.

}

// メンバ関数set_i
void class_test::set_i(int i){

  // 引数をメンバにセット.
  i_ = i; // i_にiを代入.
  //i_ = -1; // i_に-1を代入してみる.(これはできるがコメントアウトしておこう.)

}
