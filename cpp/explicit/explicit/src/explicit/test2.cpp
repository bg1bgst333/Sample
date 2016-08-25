// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test2.h" // クラスclss_test2

// class_test2のメンバの定義
// コンストラクタclass_test
class_test2::class_test2(){

  // 初期化
  set_i(0); // set_iで0をセット.

}

// 引数付きコンストラクタclass_test2(int i)
class_test2::class_test2(int i){

  // 引数の値に初期化.
  set_i(i); // set_iでiをセット.
  std::cout << "class_test2::class_test2(int i)" << std::endl; // "class_test2::class_test2(int i)"と出力.

}
