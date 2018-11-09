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
void class_presenter::changed(interface_subject *subject){
 
  // changedが呼ばれた.
  std::cout << "class_presenter::changed()" << std::endl; // "class_presenter::changed()"と出力.

  // model_のfuncを呼び出す.
  class_view *p1 = dynamic_cast<class_view *>(subject); // ダイナミックキャスト.
  if (p1 != NULL){ // p1はviewであり, viewからの通知.
    model_->func(); // model_->funcを呼ぶ.
  }
  else{
    class_model *p2 = dynamic_cast<class_model *>(subject); // ダイナミックキャスト.
    if (p2 != NULL){ // p2はmodelであり, modelからの通知.

      // モデルからプレゼンター.
      std::cout << "class_presenter::changed, model to presenter!" << std::endl; // "class_presenter::changed, model to presenter!"と出力.

      // プレゼンターからビューへ通知.
      notify(); // notifyで通知.

    }
    else{ // viewでもmodelでもない.
      std::cout << "not view, not model!" << std::endl; // "not view, not model!"と出力.
    }
  }

}

// メンバ関数set_view
void class_presenter::set_view(class_view *view){

  // 引数のviewが自身(this)をオブザーバーとする.
  view->set_observer(this); // view->set_observerにthisを指定することで, 自身がこのviewのオブザーバーとする.
  set_observer(view); // set_observerでviewをセット.

}

// メンバ関数set_model
void class_presenter::set_model(class_model *model){

  // 引数のmodelをメンバmodel_にセット.
  model_ = model; // model_にmodelをセット.

}

// メンバ関数set_observer
void class_presenter::set_observer(interface_observer *observer){

  // メンバにセット.
  observer_ = observer; // observer_にobserverをセット.

}

// メンバ関数notify
void class_presenter::notify(){

  // notifyが呼ばれた.
  std::cout << "class_presenter::notify()" << std::endl; // "class_presenter::notify()"と出力.

  // 実際にはオブザーバーのchangedを呼ぶ.
  observer_->changed(this); // observer_->changedにthisを指定して呼ぶ.

}
