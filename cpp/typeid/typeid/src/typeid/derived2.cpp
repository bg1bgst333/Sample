// ヘッダのインクルード
// 独自のヘッダ
#include "derived2.h" // クラスclass_derived2
// 既定のヘッダ
#include <iostream> // C++標準入出力

// class_derived2のメンバの定義.
// メンバ関数print_message()
void class_derived2::print_message(){

  // "class_derived2"と出力.
  std::cout << "class_derived2" << std::endl; // 出力演算子でstd::coutに"class_derived2"を出力.

}
