// 独自のヘッダ
#include "private_derived.h" // クラスclass_private_derived

// class_private_derivedのメンバの定義.
// メンバ関数print_private()
void class_private_derived::print_private(){ // class_privateのメンバを出力.

  // class_privateのメンバを出力.
  //private_variable_ = 1; // privateなのでアクセス不可.
  //private_function(); // privateなのでアクセス不可.
  //protected_variable_ = 1; // class_baseでprotected, class_privateでprivateなので, ここではアクセス不可.
  //std::cout << "protected_variable_ = " << protected_variable_ << std::endl; // class_baseでprotected, class_privateでprivateなので, ここではアクセス不可.
  //proteocd_variable_ = 1; // class_baseでprotected, class_privateでprivateなので, ここではアクセス不可.
  //public_variable_ = 1; // class_baseではpublic, class_privateではprivateなので, ここではアクセス不可.
  //std::cout << "public_variable_ = " << public_variable_ << std::endl; // class_baseではpublic, class_privateではprivateなので, ここではアクセス不可.
  //public_function(); // class_baseではpublic, class_privateではprivateなので, ここではアクセス不可.
  std::cout << "print_private" << std::endl; // "print_private"と出力することで, ここが呼ばれたことだけ示す.

}
