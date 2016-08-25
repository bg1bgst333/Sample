// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test.h" // クラスclass_test

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_test obj1; // class_testオブジェクトobj1.

  // 値の設定
  obj1.set_i(10); // obj1.set_iで10をセット.

  // 値の取得と出力.
  std::cout << "obj1.get_i() = " << obj1.get_i() << std::endl; // obj1.get_iで値を取得し, 出力.

  // プログラムの終了
  return 0;

}
