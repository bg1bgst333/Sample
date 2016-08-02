// 独自のヘッダ
#include "private.h" // クラスclass_private

// class_privateのメンバの定義.
// メンバ関数print_base()
void class_private::print_base(){ // class_baseのメンバを出力.

  // class_baseのメンバを出力.
  //private_variable = 1; // privateなのでアクセス不可.
  //private_function(); // privateなのでアクセス不可.
  protected_variable_ = 1; // private継承なのでこのクラスのprivateメンバになりアクセスは可.
  std::cout << "protected_variable_ = " << protected_variable_ << std::endl; // private継承なのでこのクラスのprivateメンバになりアクセスは可. 
  protected_function(); // private継承なのでこのクラスのprivateメンバになりアクセスは可.
  public_variable_ = 1; // private継承なのでこのクラスのprivateメンバになりアクセスは可.
  std::cout << "public_variable_ = " << public_variable_ << std::endl; // private継承なのでこのクラスのprivateメンバになりアクセスは可.
  public_function(); // private継承なのでこのクラスのprivateメンバになりアクセスは可.

}
