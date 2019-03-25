// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "input_form.h" // class_input_form
#include "data_binding.h" // class_data_binding

// main関数
int main(){

  // 入力フォームの作成.
  class_input_form<std::string> *form1_ptr = new class_input_form<std::string>("ABC"); // form1は"ABC".
  class_input_form<std::string> *form2_ptr = new class_input_form<std::string>("DEF"); // form2は"DEF".

  // データバインディング.
  class_data_binding< class_input_form<std::string> > *data_binding = new class_data_binding< class_input_form<std::string> >(); // これに登録する.

  // フォームの登録.
  data_binding->add(form1_ptr); // form1
  data_binding->add(form2_ptr); // form2

  // 現在の値を表示.
  form1_ptr->print_value(); // form1の値を出力.
  form2_ptr->print_value(); // form2の値を出力.

  // 値の変更.
  form1_ptr->set_value("XYZ"); // form1を"XYZ"に変更.

  // 再び値を表示.
  form1_ptr->print_value(); // form1の値を出力.
  form2_ptr->print_value(); // form2の値を出力.

  // 破棄.
  delete form1_ptr; // form1_ptrの解放.
  delete form2_ptr; // form2_ptrの解放.
  delete data_binding; // data_bindingの解放.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
