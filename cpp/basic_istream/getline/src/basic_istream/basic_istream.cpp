// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <cstring> // C文字列処理

// main関数
int main(){

  // 変数の宣言
  std::ifstream fin; // ファイル入出力ストリームifstream
  char buf[6]; // バッファbuf(長さ6)

  // ファイルを開く.
  fin.open("test.txt"); // openで"test.txt"を開く.
  if (!fin){ // オープン失敗.
    std::cout << "Can't open file!" << std::endl; // "Can't open file!"と出力.
    return -1; // 異常終了.
  }

  // 1行ずつ読み込む.
  while (fin.getline(buf, 6)){ // trueの間読み込む.

    // bufを出力.
    std::cout << "buf = [" << buf << "]" << std::endl; // bufを出力.

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
