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

  // コンストラクタが呼ばれたことを出力.
  std::cout << "class_test::class_test(" << x_ << ")" << std::endl; // "class_test::class_test"とxの値を出力. 

}

// デストラクタ~class_test()
class_test::~class_test(){

  // デストラクタが呼ばれたことを出力.
  std::cout << "class_test::~class_test()" << std::endl; // "class_test::~class_test()"を出力.
  std::cout << "x_ = " << x_ << std::endl; // x_の値を出力.

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

// 関数の定義
// 関数func
std::auto_ptr<class_test> func(std::auto_ptr<class_test> p){

  // pのメンバの値を出力.
  p->print(); // p->printで出力.

  // pのメンバの値を変更.
  p->set(30); // p->setで30をセット.

  // 返す.
  return p; // pを返す.

}
