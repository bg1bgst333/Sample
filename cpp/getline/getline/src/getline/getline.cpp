// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <string> // std:string

// main関数
int main(){

  // 変数の宣言
  std::ifstream fin; // ファイル入出力ストリームifstream
  std::string str; // 文字列str

  // ファイルを開く.
  fin.open("test.txt"); // openで"test.txt"を開く.
  if (!fin){ // オープン失敗.
    std::cout << "Can't open file!" << std::endl; // "Can't open file!"と出力.
    return -1; // 異常終了.
  }

  // 1行ずつ読み込む.
  while (getline(fin, str)){ // trueの間読み込む.

    // strを出力.
    std::cout << "str = [" << str << "]" << std::endl; // strを出力.

  }

  // EOFかどうかをチェック.
  if (fin.eof()){ // EOF.
    std::cout << "EOF" << std::endl; // "EOF"と出力.
  }

  // fail状態かどうかチェック.
  if (fin.fail()){ // fail状態.
    std::cout << "fail" << std::endl; // "fail"と出力.
  }

  // ファイルを閉じる.
  fin.close(); // fin.closeで閉じる.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
