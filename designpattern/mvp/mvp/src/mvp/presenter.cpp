// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "presenter.h" // class_presenter

// メンバの定義
// メンバ関数set_subject
void class_presenter::set_subject(interface_subject *subject){

  // メンバにセット.
  subject_ = subject; // subject_にsubjectをセット.

}

// メンバ関数changed
void class_presenter::changed(){
 
  // changedが呼ばれた.
  std::cout << "class_presenter::changed()" << std::endl; // "class_presenter::changed()"と出力.

  // model_のfuncを呼び出す.
  model_->func(); // model_->funcを呼ぶ.

}

// メンバ関数set_view
void class_presenter::set_view(class_view *view){

  // 引数のviewが自身(this)をオブザーバーとする.
  view->set_observer(this); // view->set_observerにthisを指定することで, 自身がこのviewのオブザーバーとする.

}

// メンバ関数set_model
void class_presenter::set_model(class_model *model){

  // 引数のmodelをメンバmodel_にセット.
  model_ = model; // model_にmodelをセット.

}
