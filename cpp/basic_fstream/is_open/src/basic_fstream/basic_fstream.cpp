// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数の定義
int main(){

  // ファイルの読み込み
  std::basic_fstream<char> f("test.txt", std::ios_base::in); // std::basic_fstream<char>で"test.txt"を開く.(std::ios_base::inを指定.)

  // 開いているかのチェック. 
  if (f.is_open()){ // 開いている.
    std::cout << "f.is_open(): true" << std::endl; // "f.is_open(): true"と出力.
  }
  else{ // 閉じている.
    std::cout << "f.is_open(): false" << std::endl; // "f.is_open(): false"と出力.
  }

  // 読み込み.
  std::string str; // std::stringのstrを用意.
  f >> str; // fから読み込んでstrに格納.
  std::cout << "str = " << str << std::endl; // strを出力.

  // 明示的に閉じる.
  f.close(); // f.closeで閉じる.

  // 開いているかのチェック. 
  if (f.is_open()){ // 開いている.
    std::cout << "f.is_open(): true" << std::endl; // "f.is_open(): true"と出力.
  }
  else{ // 閉じている.
    std::cout << "f.is_open(): false" << std::endl; // "f.is_open(): false"と出力.
  }

  // プログラムの終了
  return 0; // 正常終了

}
