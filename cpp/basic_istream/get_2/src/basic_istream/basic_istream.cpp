// ヘッダファイルのインクルード
#include <iostream> // 標準入出力
#include <string> // std::string

// main関数
int main(){

  // オブジェクトの宣言
  std::basic_istream<char> isc(std::cin.rdbuf()); // std::basic_istream<char>オブジェクトisc(ストリームバッファはstd::cin.rdbuf()から取得したものを使う.)
  char c; // 入力文字を格納するchar型変数c.

  // 文字の入力
  isc.get(c); // getで入力した文字をcに格納.
  std::cout << "c = " << c << std::endl; // cを出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
