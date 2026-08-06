// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABCDE"; // std::basic_string<char>オブジェクトstr1を"ABCDE"で初期化.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // 指定の位置posから指定の文字数n1の文字列を, 指定の文字数n2分の指定の文字cの内容に置き換える.
  str1.replace(2, 2, 2, 'X');

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
