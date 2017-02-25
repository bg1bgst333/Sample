// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test.h" // クラスclass_test

// main関数の定義
int main(){

  // 変数・オブジェクトの宣言・初期化
  int num = 1; // int型変数numを1に初期化.
  class_test test; // class_test型オブジェクトtest.

  // 左辺値参照.
  int& l_num = num; // 変数numは左辺値.
  //int&& r_num = num; // 右辺値ではない.
  class_test& l_test = test; // オブジェクトtestは左辺値.
  //class_test&& r_test = test; // 右辺値ではない.

  // 右辺値参照.
  int&& r_1 = 1; // 定数リテラルは右辺値.
  //int& l_1 = 1; // 左辺値ではない.
  class_test&& r_test = class_test(); // コンストラクタclass_test()は右辺値.
  //class_test& l_test2 = class_test(); // 左辺値ではない.
  int&& r_global = global_function(); // 関数global_function()は右辺値.
  //int& l_global = global_function(); // 左辺値ではない.

  // 値の出力.
  std::cout << "l_num = " << l_num << std::endl; // l_numを出力.
  std::cout << "r_1 = " << r_1 << std::endl; // r_1を出力.
  std::cout << "l_test.member_function = " << l_test.member_function() << std::endl; // l_test.member_function()を出力.
  std::cout << "r_test.member_function = " << r_test.member_function() << std::endl; // r_test.member_function()を出力.
  std::cout << "r_global = " << r_global << std::endl; // r_globalを出力.

  // プログラムの終了
  return 0;

}
