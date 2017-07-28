// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_text_hyphen.h" // class_print_text_hyphen

// メンバの定義
// メンバ関数print_text
void class_print_text_hyphen::print_text(std::string text){

  // ハイフンで囲んで出力.
  std::cout << "-" << text << "-" << std::endl; // 出力演算子で出力.

}
