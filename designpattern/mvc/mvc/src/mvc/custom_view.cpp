// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// メンバの定義
// メンバ関数set_custom_model
void class_custom_view::set_custom_model(class_custom_model *custom_model){

  // メンバにセット.
  custom_model_ = custom_model; // custom_model_にcustom_modeをセット.

  // オブザーバー登録.
  set_model(custom_model_); // set_modelでcustom_model_をセット.

}

// メンバ関数changed
void class_custom_view::changed(){

  // changedが呼ばれた.
  std::cout << "class_custom_view::changed()" << std::endl; // "class_custom_view::changed()"と出力.

  // custom_view_にcustom_model_の値をセット.
  x_ = custom_model_->get_x(); // custom_model_->get_xでx_を取得.
  y_ = custom_model_->get_y(); // custom_model_->get_yでy_を取得.
  result_ = custom_model_->get_result(); // custom_model_->get_resultでresult_を取得.

}
