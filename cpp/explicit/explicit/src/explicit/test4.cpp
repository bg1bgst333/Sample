// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test4.h" // クラスclass_test4

// class_test4のメンバの定義
// 引数付きコンストラクタclass_test4(const class_test2 &obj)
class_test4::class_test4(const class_test2 &obj){

  // 引数の値をメンバにセット.
  set_i(obj.get_i()); // obj.get_iで取得した値をそのままset_iでセット.
  std::cout << "class_test4::class_test4(const class_test2 &obj)" << std::endl; // "class_test4::class_test4(const class_test2 &obj)"と出力.

}

