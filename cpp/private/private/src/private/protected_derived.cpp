// 独自のヘッダ
#include "protected_derived.h" // クラスclass_protected_derived

// class_protected_derivedのメンバの定義.
// メンバ関数print_protected()
void class_protected_derived::print_protected(){ // class_protectedのメンバを出力.

  // class_protectedのメンバを出力.
  //private_variable_ = 1; // privateなのでアクセス不可.
  //private_function(); // privateなのでアクセス不可.
  protected_variable_ = 1; // protectedなのでアクセス可.
  std::cout << "protected_variable_ = " << protected_variable_ << std::endl; // protectedなのでアクセス可.
  protected_function(); // protectedなのでアクセス可.
  public_variable_ = 1; // class_baseではpublic, class_protectedではprotected, ここでもprotectedでアクセスは可.
  std::cout << "public_variable_ = " << public_variable_ << std::endl; // class_baseではpublic, class_protectedではprotected, ここでもprotectedでアクセスは可.
  public_function(); // class_baseではpublic, class_protectedではprotected, ここでもprotectedでアクセスは可.
  std::cout << "print_protected" << std::endl; // "print_protected"と出力することで, ここが呼ばれたことだけ示す.

}
