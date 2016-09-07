// ヘッダファイルのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // C++標準入出力

// class_testのメンバの定義
// コンストラクタclass_test(int x)
class_test::class_test(int x){

  // 引数の値をメンバにセット.
  x_ = x; // xをx_にセット.

}

// デストラクタ~class_test()
class_test::~class_test(){

}

// メンバ関数set(int x)
void class_test::set(int x){

  // 引数の値をメンバにセット.
  x_ = x; // xをx_にセット.

}

// メンバ関数get()
int class_test::get() const{

  // メンバの値を返す.
  return x_; // x_の値を返す.

}

// メンバ関数print()
void class_test::print(){

  // メンバの値を出力.
  std::cout << "x_ = " << x_ << std::endl; // x_の値を出力.

}
