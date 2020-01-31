// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std::string

// main関数の定義
int main(){

  // ファイルオブジェクトの宣言.
  std::basic_fstream<char> f; // std::basic_fstream<char>オブジェクトf.

  // 開いて書き込み.
  f.open("test.txt"); // f.openで"test.txt"を開く.(デフォルトでios_base::outが指定されている.)
  if (f){ // 開けた.
    f << "ABCDE" << std::endl; // fに"ABCDE"を書き込む.
    f.close(); // f.closeで明示的に閉じる.
  }
  else{ // 失敗.
    std::cout << "error!" << std::endl; // "error!"と出力.
  }

  // 開いて読み込み.
  f.open("test.txt"); // f.openで"test.txt"を開く.(デフォルトでios_base::inも指定されている.)
  if (f){ // 開けた.
    std::string str; // std::stringのstrを用意.
    f >> str; // fから読み込んでstrに格納.
    std::cout << "str = " << str << std::endl; // strを出力.
    f.close(); // f.closeで明示的に閉じる.
  }
  else{ // 失敗.
    std::cout << "error!" << std::endl; // "error!"と出力.
  }

  // プログラムの終了
  return 0; // 正常終了

}
