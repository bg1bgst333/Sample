// ヘッダのインクルード
#include <iostream> // 標準入出力
#include <unistd.h> // UNIX標準

// main関数
int main(){

  // 1つ目の文字列を出力.
  std::cout << "str1"; // 出力演算子で"str1"を出力.

  // いったんフラッシュ.
  std::cout.flush(); // std::cout.flushでバッファをいったんフラッシュ.

  // 5秒スリープ
  sleep(5); // sleepで5秒待つ.

  // 2つ目の文字列を出力.
  std::cout << "str2"; // 出力演算子で"str2"を出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
