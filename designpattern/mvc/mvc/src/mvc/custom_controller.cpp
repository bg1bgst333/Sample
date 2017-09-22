// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_controller.h" // class_custom_controller

// メンバの定義
// メンバ関数changed
void class_custom_controller::changed(){

  // changedが呼ばれた.
  std::cout << "class_custom_controller::changed()" << std::endl; // "class_custom_controller::changed()"と出力.

  // custom_view_にセットされた値の確認.
  std::cout << "custom_view_->x = " << custom_view_->x << std::endl; // custom_view_->xの出力.
  std::cout << "custom_view_->y = " << custom_view_->y << std::endl; // custom_view_->yの出力.
  std::cout << "custom_view_->result = " << custom_view_->result << std::endl; // custom_view_->resultの出力.

}

// メンバ関数set_custom_view
void class_custom_controller::set_custom_view(class_custom_view *custom_view){

  // メンバのセット.
  custom_view_ = custom_view; // custom_view_にcustom_viewをセット.

  // set_viewを呼んでオブザーバー登録.
  set_view(custom_view_); // set_viewでcustom_view_をセット. 

}
