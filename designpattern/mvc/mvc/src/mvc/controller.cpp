// 既定のヘッダ
#include <iostream> // C++標準入出力
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

// メンバ関数set_view
void class_controller::set_view(class_view *view){

  // 引数のviewが自身(this)をオブザーバーとする.
  view->set_observer(this); // view->set_observerにthisを指定することで, 自身がこのviewのオブザーバーになる.

}
