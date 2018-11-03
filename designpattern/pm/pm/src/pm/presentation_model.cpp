// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "presentation_model.h" // class_presentation_model

// メンバの定義
// メンバ関数set_subject
void class_presentation_model::set_subject(interface_subject *subject){

  // メンバにセット.
  subject_ = subject; // subject_にsubjectをセット.

}

// メンバ関数changed
void class_presentation_model::changed(){

  // changedが呼ばれた.
  std::cout << "class_presentation_model::changed()" << std::endl; // "class_presentation_model::changed()"と出力.

  // 通知.
  //notify(); // notifyで通知.

}

// メンバ関数set_observer
void class_presentation_model::set_observer(interface_observer *observer){

  // メンバにセット.
  observer_ = observer; // observer_にobserverをセット.
  observer_->set_subject(this); // observer_->set_subjectで自身(this)をセットすることでobserver_のサブジェクトになる.

}

// メンバ関数notify
void class_presentation_model::notify(){

  // notifyが呼ばれた.
  std::cout << "class_presentation_model::notify()" << std::endl; // "class_presentation_model::notify()"と出力.

  // observer_に通知.
  observer_->changed(); // 実際にはobserver_->changed()を呼び出している.

}

// メンバ関数set_view
void class_presentation_model::set_view(class_view *view){

  // viewをオブザーバーとする.
  set_observer(view); // set_observerでviewをセット.

}

// メンバ関数set_model
void class_presentation_model::set_model(class_model *model){

  // メンバにセット.
  model_ = model; // model_にmodelをセット.

}
