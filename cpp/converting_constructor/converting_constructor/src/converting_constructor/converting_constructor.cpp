// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base

// main関数の定義
int main(void){

  // オブジェクトの初期化
  class_base obj1(10); // obj1を10で初期化.
  class_base obj2("ABCDE"); // obj2を"ABCDE"で初期化.
  class_base obj3 = 20; // obj3を20で初期化.(引数1つのコンストラクタの場合は'='で渡せる.)
  class_base obj4 = "XYZ"; // obj4を"XYZ"で初期化.(引数1つのコンストラクタの場合は'='で渡せる.)

  // 出力
  obj1.show(); // obj1.showで出力.
  std::cout << std::endl; // 改行
  obj2.show(); // obj2.showで出力.
  std::cout << std::endl; // 改行
  obj3.show(); // obj3.showで出力.
  std::cout << std::endl; // 改行
  obj4.show(); // obj4.showで出力.

  // プログラムの終了
  return 0;

}
