// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // 5バイトから3バイトにリサイズ.
  str.resize(3); // str.resizeで5バイトから3バイトにリサイズ.

  // リサイズ後の文字列と文字の長さを出力.
  std::cout << str << std::endl; // strを出力.
  std::cout << str.length() << std::endl; // str.lengthを出力.

  // 3バイトから7バイトにリサイズ.
  str.resize(7); // str.resizeで3バイトから7バイトにリサイズ.

  // リサイズ後の文字列と文字の長さを出力.
  std::cout << str << std::endl; // strを出力.
  std::cout << str.length() << std::endl; // str.lengthを出力.// リサイズ後の文字列と文字の長さを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
