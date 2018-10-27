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

}
