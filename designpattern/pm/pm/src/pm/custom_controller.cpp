// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_controller.h" // class_custom_controller

// メンバ関数changed
void class_custom_controller::changed(){

  // class_custom_controller::changed()が呼ばれた.
  std::cout << "class_custom_controller::changed()" << std::endl; // "class_custom_controller::changed()"と出力.

  // 既定クラスのchanged.
  class_controller::changed(); // class_controller::changedを呼ぶ.

}

// メンバ関数set_custom_view
void class_custom_controller::set_custom_view(class_custom_view *custom_view){

  // メンバのセット.
  custom_view_ = custom_view; // custom_view_にcustom_viewをセット.

  // set_viewを呼んでオブザーバー登録.
  set_view(custom_view_); // set_viewでcustom_view_をセット.

}
