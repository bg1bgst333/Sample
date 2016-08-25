// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test3.h" // クラスclass_test3

// class_test3のメンバの定義
// 引数付きコンストラクタclass_test3(const class_test1 &obj)
class_test3::class_test3(const class_test1 &obj){

  // 引数の値をメンバにセット.
  set_i(obj.get_i()); // obj.get_iで取得した値をそのままset_iでセット.
  std::cout << "class_test3::class_test3(const class_test1 &obj)" << std::endl; // "class_test3::class_test3(const class_test1 &obj)"と出力.

}

