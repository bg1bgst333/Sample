// ヘッダのインクルード
// 独自のヘッダ
#include "print_header_footer_ex.h" // class_print_header_footer_ex
#include "print_file.h" // class_print_file

// main関数
int main(){

  // オブジェクトの宣言.
  class_print_header_footer_ex *ptr = NULL; // class_print_header_footer_exオブジェクトポインタをNULLで初期化.
  class_print_file *ptr2 = NULL; // class_print_fileオブジェクトポインタをNULLで初期化.

  // オブジェクトの生成.
  ptr = new class_print_header_footer_ex(); // class_print_header_footer_exオブジェクトを生成し, ptrに格納.
  ptr2 = new class_print_file(); // class_print_fileオブジェクトを生成し, ptr2に格納.

  // ヘッダのセット.
  ptr->set_header("--S--"); // ptr->set_headerで"--S--"をセット.

  // 本文のセット.
  ptr->set_message("ABCDE"); // ptr->set_messageで"ABCDE"をセット.

  // フッタのセット.
  ptr->set_footer("--E--"); // ptr->set_footerで"--E--"をセット.

  // ファイル名のセット.
  ptr2->set_filename("test.txt"); // ptr2->set_filenameで"test.txt"とセット.

  // 本文のセット.
  ptr2->set_message("ABCDE"); // ptr2->set_messageで"ABCDE"をセット.

  // テンプレートメソッドで出力.
  ptr->template_method(); // ptr->template_methodで出力.
  ptr2->template_method(); // ptr2->template_methodでファイル出力.

  // オブジェクトの削除.
  delete ptr; // deleteでptrを削除.
  delete ptr2; // deleteでptr2を削除.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
