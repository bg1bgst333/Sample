// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数
int main(){

  // ファイルの読み込み
  std::basic_ifstream<char> ifs("test.txt"); // std::basic_ifstream<char>のifsで"test.txt"を開く.
  std::string str; // std::stringのstrを用意.
  ifs >> str; // ifsから読み込んでstrに格納.
  std::cout << "str = " << str << std::endl; // strを出力.

  // プログラムの終了
  return 0; // 正常終了

}
