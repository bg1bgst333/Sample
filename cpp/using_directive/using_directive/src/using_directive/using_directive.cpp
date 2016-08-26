// ヘッダのインクルード
// 独自のヘッダ
#include "test1.h" // "test1.h"のクラスclass_test

// 名前空間の可視化
using namespace test1; // 名前空間test1を可視化.(省略する.)

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_test obj1; // 名前空間test1のclass_testオブジェクトobj1("test1::"を省略できている.)

  // 出力
  obj1.print(); // obj1.printで出力.

  // プログラムの終了
  return 0;

}
