// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <cstring> // C文字列処理
#include <strstream> // 文字列ストリーム

// main関数
int main(){

  // 自前の配列をバッファとして指定する.
  char buf[10]; // 要素数10.
  memset(buf, 'X', 10); // 'X'で埋める.
  std::strstream ss(buf, 10, std::ios::out); // コンストラクタにbufを渡す.

  // 文字列ストリームへの出力.
  ss << "ABC"; // ssに"ABC"を出力.

  // NULL終端する.
  ss << std::ends; // ssにendsでNULL文字を出力.

  // 配列の状態を見る.
  std::cout << "buf = " << buf << std::endl; // bufを出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
