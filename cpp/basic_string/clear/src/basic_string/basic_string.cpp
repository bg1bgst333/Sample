// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // 文字列を出力.
  std::cout << str << std::endl; // strを出力.

  // 文字列をクリアする.
  str.clear(); // std::basic_string<char>::clearで文字列をクリア.

  // 文字列を出力.
  std::cout << str << std::endl; // strを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
