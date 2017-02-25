// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test.h" // クラスclass_test.

// コンストラクタclass_test()
class_test::class_test(){

  // コンストラクタが呼ばれたことを示す.
  std::cout << "constructor" << std::endl; // "constructor"と出力.

}

// メンバ関数member_function().
int class_test::member_function(){

  // 値を返す.
  return 10; // returnで10を返す.

}

// グローバル関数global_function().
int global_function(){

  // 値を返す.
  return 100; // returnで100を返す.

}
