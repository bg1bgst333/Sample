// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <sstream> // 新文字列ストリーム

// main関数
int main(){

  // 変数の初期化.
  //std::istringstream iss("ABCDE"); // issを"ABCDE"で初期化.
  std::istringstream iss("ABC"); // issを"ABC"で初期化.
  char str[] = "XXXXXXXXXX"; // strを"XXXXXXXXXX"で初期化.

  // readsomeで読み込み.
  //iss.read(str, 5); // strに5文字読み込み.
  iss.readsome(str, 5); // strに5文字読み込み.
  std::cout << "str = " << str << std::endl; // strを出力.

  // issの状態
  if (iss.eof()){ // EOFのチェック.
    std::cout << "EOF" << std::endl; // "EOF"を出力.
  }
  if (iss.fail()){ // fail状態のチェック.
    std::cout << "fail" << std::endl; // "fail"を出力.
  }

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
