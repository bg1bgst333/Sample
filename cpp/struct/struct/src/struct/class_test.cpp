// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "class_test.h" // テストクラス

// メンバの定義
// メンバ関数show
void class_test::show(){

  // numを出力.
  std::cout << "class_test.num = " << num << std::endl; // 出力演算子でnumを出力.

}
