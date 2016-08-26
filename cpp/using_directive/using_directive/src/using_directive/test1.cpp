// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test1.h" // "test1.h"のクラスclass_test

// 名前空間test1
namespace test1{

// class_testのメンバの定義.
// メンバ関数print
void class_test::print(){

  // 出力
  std::cout << "test1" << std::endl; // "test1"と出力.

}

}
