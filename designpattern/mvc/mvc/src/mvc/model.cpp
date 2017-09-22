// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "model.h" // class_model

// メンバの定義
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
  observer_->changed();

}
