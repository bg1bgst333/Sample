// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // C++標準入出力

// class_testのメンバの定義
// メンバ関数get_i
int class_test::get_i() const{

  // 値を返す.
  j_ = 100; // j_に100を代入してみる.
  return i_; // iを返す.

}

// メンバ関数set_i
void class_test::set_i(int i){

  // 引数をメンバにセット.
  i_ = i; // i_にiを代入.
  j_ = i; // j_にもiを代入.

}

// メンバ関数show
void class_test::show(){

  // i_とj_を出力.
  std::cout << "i_ = " << i_ << ", j_ = " << j_ << std::endl;

}
