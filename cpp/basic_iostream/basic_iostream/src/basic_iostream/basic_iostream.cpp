// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数の定義
int main(){

  // ファイルの書き込み
  std::basic_fstream<char> f1("test.txt", std::ios_base::out); // std::basic_fstream<char>で"test.txt"を開く.(std::ios_base::outを指定しないと作成されない.)
  std::basic_iostream<char> *iosc_ptr = &f1; // std::basic_iostream<char>ポインタにキャスト.
  std::basic_ostream<char> *osc_ptr = iosc_ptr; // std::basic_ostream<char>ポインタにキャスト.
  osc_ptr->put('A'); // std::basic_ostream::putで'A'を書き込む.
  f1.close(); // f1.closeで明示的に閉じる.

  // ファイルの読み込み
  std::basic_fstream<char> f2("test.txt", std::ios_base::in); // std::basic_fstream<char>で"test.txt"を開く.(std::ios_base::inを指定.)
  std::basic_iostream<char> *iosc2_ptr = &f2; // std::basic_iostream<char>ポインタにキャスト.
  std::basic_istream<char> *isc_ptr = iosc2_ptr; // std::basic_istream<char>ポインタにキャスト.
  char c; // 読み込んだ文字を格納するchar型変数c.
  isc_ptr->get(c); // std::basic_istream::getで1文字読み込み, cに格納する.
  std::cout << "c = " << c <<std::endl; // cを出力.
  f2.close(); // f2.closeで明示的に閉じる.

  // プログラムの終了
  return 0; // 正常終了

}
