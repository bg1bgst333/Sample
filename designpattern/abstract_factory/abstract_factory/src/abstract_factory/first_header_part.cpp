// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "first_header_part.h" // class_first_header_part

// メンバの定義
// メンバ関数print
void class_first_header_part::print(){

  // "-----first header-----"と出力.
  std::cout << "-----first header-----" << std::endl; // 出力演算子で出力.

}
