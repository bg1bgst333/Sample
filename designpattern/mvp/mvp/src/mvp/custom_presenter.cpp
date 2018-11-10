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
    custom_model_->func(custom_view_->x_, custom_view_->y_); // custom_model_->funcで計算.
  }
  else{ // それ以外.
    class_model *p2 = dynamic_cast<class_model *>(subject); // ダイナミックキャスト.
    if (p2 != NULL){ // p2はmodelであり, modelからの通知.
      std::cout << "class_custom_presenter::changed(), subject is model!" <<std::endl; // "class_custom_presenter::changed(), subject is model!"を出力.
      int result = custom_model_->get_result();
      if (result >= 0){ // 0以上.
        start_str_ = "("; // 開始文字列は"(".
        end_str_ = ")"; // 終了文字列は")".
        std::cout << "()" << std::endl; // "()"を出力.
      }
      else{
        start_str_ = "<"; // 開始文字列は"<".
        end_str_ = ">"; // 終了文字列は">".
        std::cout << "<>" << std::endl; // "<>"を出力.
      }      
    }
    else{ // viewでもmodelでもない.
      std::cout << "not view, not model!" << std::endl; // "not view, not model!"と出力.
      class_presenter::changed(subject); // class_presenter::changedにsubjectを渡す.
    }
  }

}

// メンバ関数set_custom_view
void class_custom_presenter::set_custom_view(class_custom_view *custom_view){

  // メンバのセット.
  custom_view_ = custom_view; // custom_view_にcustom_viewをセット.

  // set_viewを呼んでオブザーバー登録.
  class_presenter::set_view(custom_view_); // class_presenter::set_viewにcustom_view_をセット.

}

// メンバ関数set_custom_model
void class_custom_presenter::set_custom_model(class_custom_model *custom_model){

  // メンバのセット.
  custom_model_ = custom_model; // custom_model_にcustom_modelをセット.

  // 親クラスのプレゼンターにセット.
  class_presenter::set_model(custom_model_); // class_presenter::set_modelでcustom_model_をセット.

  // モデルのオブザーバーにthisをセット.
  model_->set_observer(this); // thisをセット.

}
