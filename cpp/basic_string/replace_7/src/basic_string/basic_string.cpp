// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str1 = "ABCDEFGHIJ"; // std::basic_string<char>オブジェクトstr1を"ABCDEFGHIJ"で初期化.

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // イテレータi1からイテレータi2の前までをn個のcで置き換える.
  str1.replace(str1.begin() + 3, str1.begin() + 6, 3, 'X');

  // str1を出力.
  std::cout << str1 << std::endl; // str1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
