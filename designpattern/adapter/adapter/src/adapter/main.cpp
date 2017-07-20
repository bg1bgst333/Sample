// ヘッダのインクルード
// 独自のヘッダ
#include "simple_print.h" // class_simple_print
#include "adapter.h" // class_adapter

// main関数
int main(){

  // オブジェクトの宣言.
  interface_print *ptr = NULL; // interface_printオブジェクトポインタptrをNULLで初期化.
  interface_print *ptr2 = NULL; // interface_printオブジェクトポインタptr2をNULLで初期化.

  // オブジェクトの生成.
  ptr = new class_simple_print("ABCDE"); // class_simple_printオブジェクトに"ABCDE"を渡して, できたオブジェクトポインタをptrに格納.
  ptr2 = new class_adapter("VWXYZ"); // class_adapterオブジェクトに"VWXYZ"を渡して, できたオブジェクトポインタをptr2に格納.

  // メッセージの出力.
  ptr->print(); // ptr->printで出力.
  ptr2->print(); // ptr2->printで出力.

  // 削除
  delete ptr; // deleteでptrを削除.
  delete ptr2; // deleteでptr2を削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
