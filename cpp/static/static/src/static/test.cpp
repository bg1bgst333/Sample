// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test.h" // クラスclass_test

// class_testのメンバの定義.
// staticメンバ変数static_var_の宣言.
int class_test::static_var_; // int型staticメンバ変数static_var_.(これも書かなければならない.)

// staticメンバ関数static_func(int i)
void class_test::static_func(int i){

  // iをstatic_var_に格納.
  static_var_ = i; // iをstatic_var_に格納.

  // "static_func"とstatic_var_の値を出力.
  std::cout << "static_func, " << static_var_ << std::endl; // 出力演算子でstd::coutに"static_func"とstatic_var_の値を出力.

}

// メンバ関数obj_func(int i)
void class_test::obj_func(int i){

  // iをobj_var_に格納.
  obj_var_ = i; // iをobj_var_に格納.

  // "obj_func"とobj_var_の値を出力.
  std::cout << "obj_func, " << obj_var_ << std::endl; // 出力演算子でstd::coutに"obj_func"とobj_var_の値を出力.

}
