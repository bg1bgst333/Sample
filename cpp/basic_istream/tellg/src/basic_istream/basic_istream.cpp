// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <fstream> // C++ファイル入出力
#include <cstring> // C文字列処理

// main関数
int main(){

  // 変数の宣言
  std::ifstream fin; // ファイル入出力ストリームifstream
  char buf[256]; // バッファbuf(長さ256)

  // ファイルを開く.
  fin.open("test.txt"); // openで"test.txt"を開く.
  if (!fin){ // オープン失敗.
    std::cout << "Can't open file!" << std::endl; // "Can't open file!"と出力.
    return -1; // 異常終了.
  }

  // ファイルポインタの位置を出力.
  std::cout << "fin.tellg() = " << fin.tellg() << std::endl; // tellgで位置を出力.

  // 行単位読み込み.
  memset(buf, '\0', 256); // bufをクリア.
  fin.get(buf, 256); // bufで1行読み込み.
  std::cout << buf << std::endl; // bufの出力.

  // ファイルポインタの位置を出力.
  std::cout << "fin.tellg() = " << fin.tellg() << std::endl; // tellgで位置を出力.

  // 行単位読み込み.
  memset(buf, '\0', 256); // bufをクリア.
  fin.get(buf, 256); // bufで1行読み込み.
  std::cout << buf << std::endl; // bufの出力.

  // ファイルポインタの位置を出力.
  std::cout << "fin.tellg() = " << fin.tellg() << std::endl; // tellgで位置を出力.

  // fail状態かどうかチェック.
  if (fin.fail()){ // fail状態.
    std::cout << "fail" << std::endl; // "fail"と出力.
  }

  // ファイルを閉じる.
  fin.close(); // fin.closeで閉じる.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
