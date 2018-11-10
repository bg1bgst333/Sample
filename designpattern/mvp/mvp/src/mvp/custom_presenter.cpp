// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_presenter.h" // class_custom_presenter

// メンバ関数changed
void class_custom_presenter::changed(interface_subject *subject){

  // changedが呼ばれた.
  std::cout << "class_custom_presenter::changed()" << std::endl; // "class_custom_presenter::changed()"と出力.

  // model_のfuncを呼び出す.
  class_view *p1 = dynamic_cast<class_view *>(subject); // ダイナミックキャスト.
  if (p1 != NULL){ // p1はviewであり, viewからの通知.
    std::cout << "class_custom_presenter::changed(), subject is view!" << std::endl; // "class_custom_presenter::changed(), subject is view!"を出力.
  }
  else{ // それ以外.
    class_presenter::changed(subject); // class_presenter::changedにsubjectを渡す.
  }

}

// メンバ関数set_custom_view
void class_custom_presenter::set_custom_view(class_custom_view *custom_view){

  // メンバのセット.
  custom_view_ = custom_view; // custom_view_にcustom_viewをセット.

  // set_viewを呼んでオブザーバー登録.
  class_presenter::set_view(custom_view_); // class_presenter::set_viewにcustom_view_をセット.

};
