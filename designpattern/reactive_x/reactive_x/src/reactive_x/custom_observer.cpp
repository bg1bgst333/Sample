// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_observer.h" // class_custom_observer

// メンバ関数completed
void class_custom_observer::completed(){

}

// メンバ関数error
void class_custom_observer::error(){

}

// メンバ関数next
void class_custom_observer::next(std::string value){

  // 文字列を出力.
  std::cout << "value = " << value << std::endl; // valueを出力.

}
