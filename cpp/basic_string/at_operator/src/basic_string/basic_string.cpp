// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // 2番目の文字を出力.
  std::cout << str[2] << std::endl; // []演算子で2番目の要素を参照し, 出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
