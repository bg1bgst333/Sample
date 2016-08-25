// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test1.h" // クラスclass_test1

// class_test1のメンバの定義
//コンストラクタ
class_test1::class_test1(){

  // 初期化
  i_ = 0; // i_を0で初期化.

}

// 引数付きコンストラクタclass_test1(int i)
class_test1::class_test1(int i){

  // 引数の値に初期化.
  i_ = i; // 引数のiをi_に代入.
  std::cout << "class_test1::class_test1(int i)" << std::endl; // "class_test1::class_test1(int i)"と出力.

}

// メンバ関数set_i.
void class_test1::set_i(int i){

  // 引数の値をメンバにセット.
  i_ = i; // iをi_にセット.

}

// メンバ関数get_i.
int class_test1::get_i() const{ // constを付ける.

  // メンバの値を返す.
  return i_; // i_を返す.

}

// メンバ関数show.
void class_test1::show(){

  // メンバの値を出力.
  std::cout << "i_ = " << i_ << std::endl; // i_を出力.

}
