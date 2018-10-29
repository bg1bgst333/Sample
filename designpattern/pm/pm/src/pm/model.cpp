// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "model.h" // class_model

// メンバの定義
// メンバ関数func
void class_model::func(){

  // "class_model::func()"
  std::cout << "class_model::func()" << std::endl; // "class_model::func()"と出力.

  // 通知.
  notify(); // notifyで通知.

}

// メンバ関数set_observer
void class_model::set_observer(interface_observer *observer){

  // メンバにセット.
  observer_ = observer; // observer_にobserverをセット.
  observer_->set_subject(this); // observer_->set_subjectで自身(this)をセットすることでobserver_のサブジェクトになる.

}

// メンバ関数notify
void class_model::notify(){

  // notifyが呼ばれた.
  std::cout << "class_model::notify()" << std::endl; // "class_model::notify()"と出力.

  // observer_に通知.
  //observer_->changed(); // 実際にはobserver_->changed()を呼び出している.

}

// メンバ関数set_presentation_model
void class_model::set_presentation_model(class_presentation_model *presentation_model){

  // presentation_modelをオブザーバーにする.
  set_observer(presentation_model); // set_observerでpresentation_modelをセット.

}
