// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "model.h" // class_model

// メンバ関数func
void class_model::func(){

  // "class_model::func()"
  std::cout << "class_model::func()" << std::endl; // "class_model::func()"と出力.

  // observer_に通知.
  //observer_->changed(); // 実際にはobserver_->changed()を呼び出している.
  notify(); // notifyで通知.

}

// メンバ関数set_observer
void class_model::set_observer(interface_observer *observer){

  // メンバにセット.
  observer_ = observer; // observer_にobserverをセット.
  //observer_->set_subject(this); // observer_->set_subjectで自身(this)をセットすることでobserver_のサブジェクトになる.

}

// メンバ関数notify
void class_model::notify(){

  // notifyが呼ばれた.
  std::cout << "class_model::notify()" << std::endl; // "class_model::notify()"と出力.

  // observer_に通知.
  //observer_->changed();
  observer_->changed(this); // 実際にはobserver_->changed(this)を呼び出している.

}

// メンバ関数set_presenter
void class_model::set_presenter(class_presenter *presenter){

  // presenterをオブザーバーにする.
  set_observer(presenter); // set_observerでpresenterをセット.

  // presenterに自身(this)をセット.
  //presenter->set_model(this); // presenter->set_modelでthisをセット.

}
