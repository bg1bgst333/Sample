// ヘッダのインクルード
// 独自のヘッダ
#include "test1.h" // "test1.h"のクラスclass_test
#include "test2.h" // "test2.h"のクラスclass_test

// main関数の定義
int main(void){

  // オブジェクトの宣言
  test1::class_test obj1; // test1::class_testオブジェクトobj1
  test2::class_test obj2; // test2::class_testオブジェクトobj2

  // 出力
  obj1.print(); // obj1.printで出力.
  obj2.print(); // obj2.printで出力.

  // プログラムの終了
  return 0;

}
