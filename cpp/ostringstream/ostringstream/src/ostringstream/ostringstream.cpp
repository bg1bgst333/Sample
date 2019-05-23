// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <sstream> // 新文字列ストリーム

// main関数
int main(){

  // 文字列ストリームの宣言.
  std::ostringstream oss; // ossを宣言.

  // 文字列の出力.
  oss << "ABC"; // ossに"ABC"を出力.

  // 整数値の出力.
  oss << 123; // ossに123を出力.

  // 浮動小数値の出力.
  oss << 0.456; // ossに0.456を出力.

  // バッファの状態を見る.
  std::cout << "oss.str() = " << oss.str() << std::endl; // oss.str()でバッファにアクセス.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
