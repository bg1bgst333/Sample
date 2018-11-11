// ヘッダのインクルード
// 独自のヘッダ
#include "round_brackets.h" // class_round_brackets

// メンバ関数create_brackets_string
std::string class_round_brackets::create_brackets_string(std::string str){

  // 丸括弧付きの文字列を返す.
  return "(" + str + ")"; // strの前後を"("と")"で囲んで返す.

}

  
