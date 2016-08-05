// ヘッダのインクルード
// 独自のヘッダ
#include "derived1.h" // クラスclass_derived1
// 既定のヘッダ
#include <iostream> // C++標準入出力

// class_derived1のメンバの定義.
// メンバ関数print_message()
void class_derived1::print_message(){

  // "class_derived1"と出力.
  std::cout << "class_derived1" << std::endl; // 出力演算子でstd::coutに"class_derived1"を出力.

}
