// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <cstring> // C文字列操作
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクト, 配列の宣言, 初期化.
  std::basic_string<char> str; // basic_string<char>で宣言したstr.
  char buf[256] = {'\0'}; // char型配列bufを'/0'で初期化.

  // 文字列の代入.
  str = "ABCDE"; // strに"ABCDE"を代入.

  // strをbufにコピー.
  strcpy(buf, str.c_str()); // str.c_strでstrのC言語のchar型配列における先頭アドレスを取得, strの内容をstrcpyでbufにコピー.

  // strとbufを出力.
  std::cout << "str = " << str << std::endl; // strの内容を出力.
  std::cout << "buf = " << buf << std::endl; // bufの内容を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
