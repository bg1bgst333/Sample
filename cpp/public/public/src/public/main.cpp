// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base
#include "public.h" // クラスclass_public

// main関数の定義
int main(){

  // オブジェクトの宣言
  class_base b; // class_baseオブジェクトb
  class_public p; // class_publicオブジェクトp

  // bのメンバにアクセス.
  //b.private_variable_ = 1; // privateなのでアクセス不可.
  //b.private_function(); // privateなのでアクセス不可.
  //b.protected_variable_ = 1; // protectedなのでアクセス不可.
  //b.protected_function(); // protectedなのでアクセス不可.
  b.public_variable_ = 1; // publicなのでアクセス可.
  std::cout << "b.public_variable_ = " << b.public_variable_ << std::endl; // publicなのでアクセス可.
  b.public_function(); // publicなのでアクセス可.

  // pのメンバにアクセス.
  //p.private_variable_ = 1; // privateなのでアクセス不可.
  //p.private_function(); // privateなのでアクセス不可.
  //p.protected_variable_ = 1; // protectedなのでアクセス不可.
  //p.protected_function(); // protectedなのでアクセス不可.
  p.public_variable_ = 1; // publicなのでアクセス可.
  std::cout << "p.public_variable_ = " << p.public_variable_ << std::endl; // publicなのでアクセス可.
  p.public_function(); // publicなのでアクセス可.

  // print_baseで出力.
  p.print_base(); // p.print_baseでメンバを出力.

  // プログラムの終了
  return 0;

}
