// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// メンバ関数notify
void class_custom_view::notify(){

  // class_custom_view::notifyが呼ばれた.
  std::cout << "class_custom_view::notify()" << std::endl; // "class_custom_view::notify()"と出力.

  // 通知.
  class_view::notify(); // class_view::notify()を呼ぶ.

}

// メンバ関数set_custom_presenter
void class_custom_view::set_custom_presenter(class_custom_presenter *custom_presenter){

  // メンバにセット.
  custom_presenter_ = custom_presenter; // custom_presenter_にcustom_presenterをセット.

}

// メンバ関数changed
void class_custom_view::changed(interface_subject *subject){

  // changedが呼ばれた.
  std::cout << "class_custom_view::changed()" << std::endl; // "class_custom_view::changed()"と出力.

  // 各値を取得.
  x_ = custom_presenter_->get_x(); // x_に格納.
  y_ = custom_presenter_->get_y(); // y_に格納.
  result_ = custom_presenter_->get_result(); // result_に格納.
  std::string start_str = custom_presenter_->get_start_str(); // start_strに格納.
  std::string end_str = custom_presenter_->get_end_str(); // end_strに格納.
  std::cout << start_str << x_ << " + " << y_ << " = " << result_ << end_str << std::endl; // 計算式を出力.
  
  // 親クラスのchangedにsubjectを渡す.
  class_view::changed(subject); // class_view::changedにsubjectを渡す.

}
