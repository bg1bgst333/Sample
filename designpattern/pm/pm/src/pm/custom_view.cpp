// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// メンバ関数notify
void class_custom_view::notify(){

  // class_custom_view::notifyが呼ばれた.
  std::cout << "class_custom_view::notify()" << std::endl; // "class_custom_view::notify()"と出力.

  // 通知.
  class_view::notify(); // class_view::notify()を呼ぶ.

}

// メンバ関数changed
void class_custom_view::changed(){

  // changedが呼ばれた.
  std::cout << "class_custom_view::changed()" << std::endl; // "class_custom_view::changed()"と出力.

  // custom_presentation_modelから値を取得.
  class_custom_presentation_model *custom_presentation_model = dynamic_cast<class_custom_presentation_model *>(presentation_model_); // presentation_model_をclass_custom_presentation_modelポインタにダイナミックキャスト.
  if (custom_presentation_model != NULL){ // ダイナミックキャスト成功.
    std::string start_str = custom_presentation_model->get_start_str(); // start_strを取得.
    std::string end_str = custom_presentation_model->get_end_str(); // end_strを取得.
    x_ = custom_presentation_model->get_x(); // x_を取得.
    y_ = custom_presentation_model->get_y(); // y_を取得.
    result_ = custom_presentation_model->get_result(); // result_を取得.
    std::cout << start_str << x_ << " + " << y_ << " = " << result_ << end_str << std::endl;
  }

  // 基底クラスのchangedを呼ぶ.
  class_view::changed(); // class_view::changedを呼ぶ.

}

// メンバ関数set_custom_presentation_model
void class_custom_view::set_custom_presentation_model(class_custom_presentation_model *custom_presentation_model){

  // 基底クラスのメンバを呼ぶ.
  class_view::set_presentation_model(custom_presentation_model); // class_view::set_presentation_modelでcustom_presentation_modelをセット.

}
