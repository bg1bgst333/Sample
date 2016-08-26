// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "using_declaration.h" // 名前空間test1, test2, test3

// main関数の定義
int main(void){

  // test1::x, test2::y, test2::zブロック
  {

    // どの変数がどの名前空間かを宣言しておく.
    using test1::x;
    using test2::y;
    using test2::z;

    // 値の代入(この部分についてはすっきりする.)
    x = 1;
    y = 2;
    z = 3;

    // 値の出力(この部分についてはすっきりする.)
    std::cout << x << "," << y << "," << z << std::endl;

  }

  // test3::x, test2::y, test2::zブロック
  {

    // どの変数がどの名前空間かを宣言しておく.
    using test3::x;
    using test2::y;
    using test2::z;

    // 値の代入(この部分についてはすっきりする.)
    x = 4;
    y = 5;
    z = 6;

    // 値の出力(この部分についてはすっきりする.)
    std::cout << x << "," << y << "," << z << std::endl;

  }

  // test3::x, test1::y, test3::zブロック
  {

    // どの変数がどの名前空間かを宣言しておく.
    using test3::x;
    using test1::y;
    using test3::z;

    // 値の代入(この部分についてはすっきりする.)
    x = 7;
    y = 8;
    z = 9;

    // 値の出力(この部分についてはすっきりする.)
    std::cout << x << "," << y << "," << z << std::endl;

  }

  // プログラムの終了
  return 0;

}
