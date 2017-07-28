// ヘッダのインクルード
// 独自のヘッダ
#include "print.h" // class_print
#include "print_text_hyphen.h" // class_print_text_hyphen
#include "print_text_asterisk.h" // class_print_text_asterisk

// main関数
int main(){

  // print, print2オブジェクトの生成.
  class_print *print = new class_print(new class_print_text_hyphen()); // class_printのコンストラクタにclass_print_text_hyphenオブジェクトポインタを渡して生成し, オブジェクトポインタをprintに格納.
  class_print *print2 = new class_print(new class_print_text_asterisk()); // class_printのコンストラクタにclass_print_text_asteriskオブジェクトポインタを渡して生成し, オブジェクトポインタをprintに格納.

  // テキストの出力.
  print->print("ABCDE"); // print->printで"ABCDE"を出力.
  print2->print("VWXYZ"); // print2->printで"VWXYZ"を出力.

  // 数値の出力.
  print->print(10); // print->printで10を出力.
  print2->print(20); // print2->printで20を出力.

  // print, print2の破棄.
  delete print; // deleteでprintを破棄.
  delete print2; // deleteでprint2を破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
