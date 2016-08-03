// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test.h" // クラスclass_test

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_test test_obj; // class_testオブジェクトtest_obj

  // test_objのメンバにアクセス.
  test_obj.obj_var_ = 5; // test_obj.obj_var_に5を代入.
  std::cout << test_obj.obj_var_ << std::endl; // test_obj.obj_var_の値を出力.
  test_obj.obj_func(10); // test_obj.obj_funcに10を渡して実行.

  // class_testのstaticメンバにアクセス.
  class_test::static_var_ = 50; // class_test::static_var_に50を代入.
  std::cout << class_test::static_var_ << std::endl; // class_test::static_var_の値を出力.
  class_test::static_func(100); // class_test::static_funcに100を渡して実行.

  // プログラムの終了
  return 0;

}
