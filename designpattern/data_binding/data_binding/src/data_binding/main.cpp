// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "binding_variable.h" // class_binding_variable
#include "input_form.h" // class_input_form
#include "key_binder.h" // class_key_binder

// main関数
int main(){

  // セッター, ゲッター, コンパレーターの生成.
  class_setter<class_input_form<std::string>, std::string> setter; // class_input_form<std::string>用のsetterを用意.
  class_getter<class_input_form<std::string>, std::string> getter; // class_input_form<std::string>用のgetterを用意.
  class_comparator<std::string> comparator; // class_comparator; // std::string用のcomparatorを用意.

  // バインディング変数の初期化.
  class_binding_variable<class_input_form<std::string>, std::string> binding_str("ABC", setter, getter, comparator); // binding_strに"ABC", setter, getter, comparatorをセット.

  // 入力フォームの初期化.
  class_input_form<std::string> form1("hoge"); // form1を"hoge"で初期化.
  class_input_form<std::string> form2("foo"); // form2を"foo"で初期化.
  class_input_form<std::string> form3("bar"); // form3を"bar"で初期化.

  // 入力フォームの値を出力.
  form1.print_value(); // form1.print_valueでform1の値を出力.
  form2.print_value(); // form2.print_valueでform2の値を出力.
  form3.print_value(); // form3.print_valueでform3の値を出力.

  // 区切り線を引く.
  std::cout << "-----" << std::endl; // "-----"を出力.

  // 入力フォームに値をセット.
  form2.set_value("AAA"); // form2.set_valueでform2に"AAA"をセット.

  // 入力フォームの値を出力.
  form1.print_value(); // form1.print_valueでform1の値を出力.
  form2.print_value(); // form2.print_valueでform2の値を出力.
  form3.print_value(); // form3.print_valueでform3の値を出力.

  // 区切り線を引く.
  std::cout << "-----" << std::endl; // "-----"を出力.

  // バインダーの生成.
  class_key_binder<class_input_form<std::string>> binder; // class_input_form<std::string>用のbinderを生成.

  // バインディング変数と入力フォームをバインド.
  binder.bind(&binding_str, &form1); // binding_strとform1をバインド.
  binder.bind(&binding_str, &form2); // binding_strとform2をバインド.
  binder.bind(&binding_str, &form3); // binding_strとform3をバインド.

  // 入力フォームの値を出力. 
  form1.print_value(); // form1.print_valueでform1の値を出力.
  form2.print_value(); // form2.print_valueでform2の値を出力.
  form3.print_value(); // form3.print_valueでform3の値を出力.

  // 区切り線を引く.
  std::cout << "-----" << std::endl; // "-----"を出力.

  // 入力フォームに値をセット.
  form3.set_value("BBB"); // form3.set_valueでform3に"BBB"をセット.

  // 入力フォームの値を出力.
  form1.print_value(); // form1.print_valueでform1の値を出力.
  form2.print_value(); // form2.print_valueでform2の値を出力.
  form3.print_value(); // form3.print_valueでform3の値を出力.

  // 区切り線を引く.
  std::cout << "-----" << std::endl; // "-----"を出力.

  // 入力フォームに値をセット.
  form1.set_value("CCC"); // form1.set_valueでform1に"CCC"をセット.

  // 入力フォームの値を出力.
  form1.print_value(); // form1.print_valueでform1の値を出力.
  form2.print_value(); // form2.print_valueでform2の値を出力.
  form3.print_value(); // form3.print_valueでform3の値を出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
