// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "simple_print.h" // class_simple_print

// メンバの定義
// メンバ関数print
void class_simple_print::print(std::string str){

  // 出力.
  std::cout << str << std::endl; // strを出力.

}
