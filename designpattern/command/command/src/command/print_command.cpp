// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <sstream> // 文字列ストリーム
// 独自のヘッダ
#include "print_command.h" // class_print_command

// メンバの定義
// メンバ関数prepare
bool class_print_command::prepare(std::string param_str){

  // パラメータのパース.
  std::stringstream ss; // 文字列ストリームss.
  ss << param_str; // param_strをssに出力.
  std::string command; // コマンド文字列.
  std::string param; // パース済みパラメータ文字列.
  ss >> command; // ssの出力をcommandに格納.
  if (!ss.eof()){ // eofでなければ.
    ss >> param; // ssの出力をparamに格納.
    str_ = param; // paramをstr_に格納.
  }

  // 真を返す.
  return true; // trueを返す.

}

// メンバ関数execute
bool class_print_command::execute(){

  // パラメータの文字列を出力.
  std::cout << ">>" << str_ << std::endl; // str_を出力.

  // 真を返す.
  return true; // trueを返す.

}
