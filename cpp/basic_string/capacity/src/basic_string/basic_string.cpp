// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <string> // C++文字列

// main関数
int main(){

  // オブジェクトの宣言と初期化.
  std::basic_string<char> str = "ABCDE"; // std::basic_string<char>オブジェクトstrを"ABCDE"で初期化.

  // メモリを再確保せずに格納できる最大の長さを取得する.
  std::cout << str.capacity() << std::endl; // str.capacityを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
