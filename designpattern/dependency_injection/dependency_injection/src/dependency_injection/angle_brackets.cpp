// ヘッダのインクルード
// 独自のヘッダ
#include "angle_brackets.h" // class_angle_brackets

// メンバ関数create_brackets_string
std::string class_angle_brackets::create_brackets_string(std::string str){

  // 角括弧付きの文字列を返す.
  return "<" + str + ">"; // strの前後を"<"と">"で囲んで返す.

}
