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
  std::cout << "custom_view_->x_ = " << custom_view_->x_ << std::endl; // custom_view_->x_の出力.
  std::cout << "custom_view_->y_ = " << custom_view_->y_ << std::endl; // custom_view_->y_の出力.
  std::cout << "custom_view_->result_ = " << custom_view_->result_ << std::endl; // custom_view_->result_の出力.

  // モデルの実行関数を呼ぶ.
  custom_model_->func(custom_view_->x_, custom_view_->y_); // custom_model_->funcにcustom_view_->x_, custom_view_->y_を渡す.

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

  // set_custom_modelを呼んでcustom_view_をオブザーバーとして登録.
  custom_view_->set_custom_model(custom_model_); // custom_view_->set_custom_modelでcustom_model_をセット.

}
