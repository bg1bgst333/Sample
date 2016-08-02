// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base
#include "private.h" // クラスclass_private
#include "protected_derived.h" // クラスclass_protected_derived
#include "private_derived.h" // クラスclass_private_derived

// main関数の定義
int main(void){

  // オブジェクトの宣言
  class_protected p1; // class_protectedオブジェクトp1
  class_private p2; // class_privateオブジェクトp2
  class_protected_derived protected_d; // class_protected_derivedオブジェクトprotected_d
  class_private_derived private_d; // class_private_derivedオブジェクトprivate_d

  // print_baseで出力.
  p1.print_base(); // p1.print_baseでメンバを出力.
  p2.print_base(); // p2.print_baseでメンバを出力.

  // protected継承だと, publicだったメンバもprotectedになるのでアクセス不可.
  //p1.public_variable_ = 1; // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.
  //std::cout << "p1.public_variable_ = " << p1.public_variaable_ << std::endl; // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.
  //p1.public_function(); // 基底クラスではpublicなのでアクセス可だったが, protectedになりアクセス不可.

  // private継承だと, publicだったメンバもprivateになるのでアクセス不可.
  //p2.public_variable_ = 1; // 基底クラスではpublicなのでアクセス可だったが, privateになりアクセス不可.
  //std::cout << "p2.public_variable_ = " << p2.public_variaable_ << std::endl; // 基底クラスではpublicなのでアクセス可だったが, privateになりアクセス不可.
  //p2.public_function(); // 基底クラスではpublicなのでアクセス可だったが, privateになりアクセス不可.

  // print_protectedで出力.
  protected_d.print_protected(); // protected_d.print_protectedでメンバを出力.

  // print_privateで出力.
  private_d.print_private(); // private_d.print_privateでメンバを出力.
 
  // プログラムの終了
  return 0;

}
