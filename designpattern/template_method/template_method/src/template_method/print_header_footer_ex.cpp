// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "print_header_footer_ex.h" // class_print_header_footer_ex

// メンバの定義
// メンバ関数set_header
void class_print_header_footer_ex::set_header(std::string header){

  // メンバのセット
  header_ = header; // headerをheader_にセット.

}

// メンバ関数set_message
void class_print_header_footer_ex::set_message(std::string message){

  // メンバのセット
  message_ = message; // messageをmessage_にセット.

}

// メンバ関数set_footer
void class_print_header_footer_ex::set_footer(std::string footer){

  // メンバのセット
  footer_ = footer; // footerをfotter_にセット.

}

// メンバ関数begin_print
bool class_print_header_footer_ex::begin_print(){

  // ヘッダの出力
  std::cout << header_ << std::endl; // header_を出力.
  return true; // trueを返す.

}

// メンバ関数print
bool class_print_header_footer_ex::print(){

  // 本文の出力
  std::cout << message_ << std::endl; // message_を出力.
  return true; // trueを返す.

}

// メンバ関数end_print
bool class_print_header_footer_ex::end_print(){

  // フッタの出力
  std::cout << footer_ << std::endl; // footer_を出力.
  return true; // trueを返す.

}
