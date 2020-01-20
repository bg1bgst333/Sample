// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数の定義
int main(){

  // ファイルの書き込み
  std::basic_fstream<char> f1("test.txt", std::ios_base::out); // std::basic_fstream<char>で"test.txt"を開く.(std::ios_base::outを指定しないと作成されない.)
  f1 << "ABCDE" << std::endl; // f1に"ABCDE"を書き込む.
  f1.close(); // f1.closeで明示的に閉じる.

  // ファイルの読み込み
  std::basic_fstream<char> f2("test.txt", std::ios_base::in); // std::basic_fstream<char>で"test.txt"を開く.(std::ios_base::inを指定.)
  std::string str; // std::stringのstrを用意.
  f2 >> str; // f2から読み込んでstrに格納.
  std::cout << "str = " << str << std::endl; // strを出力.

  // プログラムの終了
  return 0; // 正常終了

}
