// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio> // C標準入出力
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "framed_string.h" // class_framed_string

// メンバの定義
// コンストラクタclass_framed_string
class_framed_string::class_framed_string(std::string str){

  // メンバにセット.
  str_ = str; // strをstr_にセット.

}

// メンバ関数print
void class_framed_string::print(){

  // 上枠の出力.
  for (int i = 0; i < str_.length() + 2; i++){ // 長さ + 2.
    putchar('*'); // putcharで'*'を出力.
  }

  // 左枠の出力.
  putchar('\n'); // 改行を出力.
  putchar('*'); // '*'を出力.

  // 文字列の出力.
  std::cout << str_; // str_を出力.

  // 右枠の出力.
  putchar('*'); // '*'を出力.
  putchar('\n'); // 改行を出力.

  // 下枠の出力.
  for (int i = 0; i < str_.length() + 2; i++){ // 長さ + 2.
    putchar('*'); // putcharで'*'を出力.
  }

  // 改行.
  std::cout << std::endl; // 改行を出力.

}
