// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "simple_print.h" // class_simple_print

// メンバの定義
// コンストラクタ
class_simple_print::class_simple_print(std::string message){

  // メンバにセット
  message_ = message; // messageをmessage_にセット.

}

// メンバ関数set_message
void class_simple_print::set_message(std::string message){

  // メンバにセット
  message_ = message; // messageをmessage_にセット.

}

// メンバ関数print
void class_simple_print::print(){

  // message_を出力.
  std::cout << message_ << std::endl; // message_を出力.

}
