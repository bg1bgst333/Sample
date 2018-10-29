// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// メンバ関数notify
void class_custom_view::notify(){

  // class_custom_view::notifyが呼ばれた.
  std::cout << "class_custom_view::notify()" << std::endl; // "class_custom_view::notify()"と出力.

  // 通知.
  class_view::notify(); // class_view::notify()を呼ぶ.

}
