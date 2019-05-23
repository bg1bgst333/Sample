// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <sstream> // 新文字列ストリーム
#include <string> // std::string

// main関数
int main(){

  // 変数の初期化.
  std::istringstream iss("ABC 123 0.456"); // issを"ABC 123 0.456"で初期化.
  std::string str = ""; // strを""で初期化.
  int i = 0; // iを0で初期化.
  float f = 0.0; // fを0.0で初期化.

  // 文字列からそれぞれの値を取り出す.
  iss >> str >> i >> f; // issから取り出した値をstr, i, fに格納.

  // 値の出力.
  std::cout << "str = " << str << std::endl; // strの値を出力.
  std::cout << "i = " << i << std::endl; // iの値を出力.
  std::cout << "f = " << f << std::endl; // fの値を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
