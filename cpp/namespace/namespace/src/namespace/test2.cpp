// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test2.h" // "test2.h"のクラスclass_test

// 名前空間test2
namespace test2{

// class_testのメンバの定義.
// メンバ関数print
void class_test::print(){

  // 出力
  std::cout << "test2" << std::endl; // "test2"と出力.

}

}
