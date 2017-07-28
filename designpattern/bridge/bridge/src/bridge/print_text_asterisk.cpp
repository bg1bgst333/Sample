// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_text_asterisk.h" // class_print_text_asterisk

// メンバの定義
// メンバ関数print_text
void class_print_text_asterisk::print_text(std::string text){

  // アスタリスクで囲んで出力.
  std::cout << "*" << text << "*" << std::endl; // 出力演算子で出力.

}
