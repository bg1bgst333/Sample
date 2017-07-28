// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_base.h" // class_print_base

// メンバの定義
// コンストラクタclass_print_base
class_print_base::class_print_base(interface_print_text *print_text){

  // メンバにセット.
  print_text_ = print_text; // print_textをprint_text_にセット.

}

// デストラクタ~class_print_base
class_print_base::~class_print_base(){

  // 持っているprint_text_の破棄.
  delete print_text_; // deleteでprint_text_を破棄.

}

// メンバ関数print(std::string)
void class_print_base::print(std::string text){

  // 実装クラスのメソッドに任せる.
  print_text_->print_text(text); // textをprint_text_->print_textに渡して任せる.

}

// メンバ関数print(int)
void class_print_base::print(int num){

  // ここで出力する.
  std::cout << num << std::endl; // numを出力.

}
