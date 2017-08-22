// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // 標準入出力
#include <memory> // メモリ管理

// main関数
int main(){

  // unique_ptrの生成.
  std::unique_ptr<class_test> p1(new class_test(10)); // class_testオブジェクトポインタをunique_ptrのp1に渡す.

  // p1の値を出力.
  p1->print(); // p1->printで出力.

  // unique_ptrのコピーとムーブ.
  std::unique_ptr<class_test> p2; // unique_ptrのp2を宣言.
  //p2 = p1; // p1をp2にコピーすることはできない.
  p2 = std::move(p1); // p1をp2にムーブはすることはできる.

  // p2の値を出力.
  p2->print(); // p2->printで出力.

  // p1の存在をチェック.
  if (!p1){ // p1が偽なら.
    std::cout << "p1 is false!" << std::endl; // "p1 is false!"と出力.
  }

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
