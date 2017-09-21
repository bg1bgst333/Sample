// 独自のヘッダ
#include "controller.h" // class_controller

// メンバの定義
// メンバ関数set_subject
void class_controller::set_subject(interface_subject *subject){

  // メンバにセット.
  subject_ = subject; // subject_にsubjectをセット.

}

// メンバ関数changed
void class_controller::changed(){

  // changedが呼ばれた.
  std::cout << "class_controller::changed()" << std::endl; // "class_controller::changed()"と出力.

}
