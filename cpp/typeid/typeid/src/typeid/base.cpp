// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base
// 既定のヘッダ
#include <iostream> // C++標準入出力

// class_baseのメンバの定義.
// メンバ関数print_message()
void class_base::print_message(){

  // "class_base"と出力.
  std::cout << "class_base" << std::endl; // 出力演算子でstd:coutに"class_base"を出力.

}
