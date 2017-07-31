// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "simple_print.h" // class_simple_print
#include "hyphen_print.h" // class_hyphen_print
#include "bracket_print.h" // class_bracket_print

// main関数
int main(){

  // デコレーション.
  interface_print *print = new class_hyphen_print(new class_simple_print("ABCDE")); // "ABCDE"を渡したclass_simple_printにclass_hyphen_printのデコレーションをして, printに格納.
  interface_print *print2 = new class_bracket_print(new class_simple_print("FGHIJ")); // "FGHIJ"を渡したclass_simple_printにclass_bracket_printのデコレーションをして, printに格納.

  // ダブルデコレーション.
  interface_print *print3 = new class_bracket_print(new class_hyphen_print(new class_simple_print("XYZ"))); // ハイフンの外に括弧.
  interface_print *print4 = new class_hyphen_print(new class_bracket_print(new class_simple_print("ZYX"))); // 括弧の外にハイフン.
  
  // テキストを取得して出力.
  std::cout << print->get_text() << std::endl; // print->get_text()を出力.
  std::cout << print2->get_text() << std::endl; // print2->get_text()を出力.
  std::cout << print3->get_text() << std::endl; // print3->get_text()を出力.
  std::cout << print4->get_text() << std::endl; // print4->get_text()を出力.

  // printを破棄.
  delete print; // deleteでprintを破棄.
  delete print2; // deleteでprint2を破棄.
  delete print3; // deleteでprint3を破棄.
  delete print4; // deleteでprint4を破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
