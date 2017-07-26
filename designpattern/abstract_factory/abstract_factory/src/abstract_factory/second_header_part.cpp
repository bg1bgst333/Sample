// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "second_header_part.h" // class_second_header_part

// メンバの定義
// メンバ関数print
void class_second_header_part::print(){

  // "-----second header-----"と出力.
  std::cout << "-----second header-----" << std::endl; // 出力演算子で出力.

}
