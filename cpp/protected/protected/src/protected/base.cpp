// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseのメンバの定義.
// メンバ関数private_function()
void class_base::private_function(){ // "private_function"と出力.

  // "private_function"と出力.
  std::cout << "private_function" << std::endl; // 出力演算子でstd::coutに"private_function"と出力.

}

// メンバ関数protected_function()
void class_base::protected_function(){ // "protected_function"と出力.

  // "protected_function"と出力.
  std::cout << "protected_function" << std::endl; // 出力演算子でstd::coutで"protected_function"と出力.

}

// メンバ関数public_function"と出力.
void class_base::public_function(){ // "public_function"と出力.

  // "public_function"と出力.
  std::cout << "public_function" << std::endl; // 出力演算子でstd::coutで"public_function"と出力.

}
