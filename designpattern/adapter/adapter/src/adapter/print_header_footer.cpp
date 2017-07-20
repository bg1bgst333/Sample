// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_header_footer.h" // class_print_header_footer

// メンバの定義
// コンストラクタ
class_print_header_footer::class_print_header_footer(){

}

// デストラクタ
class_print_header_footer::~class_print_header_footer(){

}

// メンバ関数print_header
void class_print_header_footer::print_header(std::string header){

  // headerを出力.
  std::cout << header << std::endl; // 出力演算子でheaderを出力.

}

// メンバ関数print_footer
void class_print_header_footer::print_footer(std::string footer){

  // footerを出力.
  std::cout << footer << std::endl; // 出力演算子でfooterを出力.

}
