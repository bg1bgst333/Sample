// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // 文字列

// main関数
int main(){

  // stringの初期化.
  std::string str = "ABCDE"; // std::stringオブジェクトのstrを"ABCDE"で初期化.

  // strの出力
  std::cout.write(str.c_str(), str.size()); // std::cout.writeでstrを出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
