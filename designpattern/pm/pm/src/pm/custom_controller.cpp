// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_controller.h" // class_custom_controller

// メンバ関数changed
void class_custom_controller::changed(){

  // class_custom_controller::changed()が呼ばれた.
  std::cout << "class_custom_controller::changed()" << std::endl; // "class_custom_controller::changed()"と出力.

  // custom_model_のfuncを呼ぶ.
  custom_model_->func(custom_view_->x_, custom_view_->y_); // custom_model_->funcで計算.

}

// メンバ関数set_custom_view
void class_custom_controller::set_custom_view(class_custom_view *custom_view){

  // メンバのセット.
  custom_view_ = custom_view; // custom_view_にcustom_viewをセット.

  // set_viewを呼んでオブザーバー登録.
  set_view(custom_view_); // set_viewでcustom_view_をセット.

}

// メンバ関数set_custom_model
void class_custom_controller::set_custom_model(class_custom_model *custom_model){

  // メンバのセット.
  custom_model_ = custom_model; // custom_model_にcustom_modelをセット.

  // set_modelでサブジェクト登録.
  set_model(custom_model_); // set_modelでcustom_model_をセット.

}
