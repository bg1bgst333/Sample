// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // class_test
// 既定のヘッダ
#include <iostream> // 標準入出力

// メンバの定義
// コンストラクタclass_test
class_test::class_test(int x){

  // 引数の値をメンバにセット.
  x_ = x; // xをx_にセット.

  // コンストラクタが呼ばれたことを出力.
  std::cout << "class_test::class_test(" << x_ << ")" << std::endl; // x_の値を出力.

}

// デストラクタ~class_test
class_test::~class_test(){

  // デストラクタが呼ばれたことを出力.
  std::cout << "class_test::~class_test()" << std::endl; // "class_test::~class_test()"を出力.

}

// メンバ関数set
void class_test::set(int x){

  // 引数の値をメンバにセット.
  x_ = x; // xをx_にセット.

}

// メンバ関数get
int class_test::get() const{

  // メンバの値を返す.
  return x_; // x_を返す.

}

// メンバ関数print
void class_test::print(){

  // メンバの値を出力.
  std::cout << "x_ = " << x_ << std::endl; // xの値を出力.

}
