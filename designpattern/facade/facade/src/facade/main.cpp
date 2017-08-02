// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "front.h" // class_front

// main関数
int main(){

  // data1を探す.
  if (class_front::search("data1")){ // class_front::searchで"data1"を探す.
    std::cout << "data1 exist and valid!" << std::endl; // "data1 exist and valid!"を出力.
  }

  // data10を探す.
  if (class_front::search("data10")){ // class_front::searchで"data10"を探す.
    std::cout << "data10 exist and valid!" << std::endl; // "data1i0 exist and valid!"を出力.
  }

  // data3を探す.
  if (class_front::search("data3")){ // class_front::searchで"data3"を探す.
    std::cout << "data3 exist and valid!" << std::endl; // "data1i0 exist and valid!"を出力.
  }

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
