// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "struct_test.h" // テスト構造体

// メンバの定義
// メンバ関数show
void struct_test::show(){

  // numを出力.
  std::cout << "struct_test.num = " << num << std::endl; // 出力演算子でnumを出力.

}
