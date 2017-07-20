// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "adapter.h" // class_adapter

// メンバの定義
// コンストラクタ
class_adapter::class_adapter(std::string message){

  // メンバにセット.
  message_ = message; // messageをmessage_にセット.

}

// デストラクタ
class_adapter::~class_adapter(){

}

// メンバ関数print
void class_adapter::print(){

  // ヘッダ出力.
  print_header("--S--"); // print_headerで"--S--"を出力.

  // message_を出力.
  std::cout << message_ << std::endl; // message_を出力.

  // フッタ出力.
  print_footer("--E--"); // print_footerで"--E--"を出力.

}
