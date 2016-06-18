// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base
#include "protected.h" // クラスclass_protected

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_protected p; // class_protectedオブジェクトp

  // print_baseで出力.
  p.print_base(); // p.print_baseでメンバを出力.

  // protected継承だと, publicだったメンバもprotectedになるのでアクセス不可.
  //p.public_variable_ = 1; // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.
  //std::cout << "p.public_variable_ = " << p.public_variable_ << std::endl; // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.
  //p.public_function(); // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.

  // プログラムの終了
  return 0;

}
