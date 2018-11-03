// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_presentation_model.h" // class_custom_presentation_model
#include "custom_model.h" // class_custom_model

// メンバ関数changed
void class_custom_presentation_model::changed(){

  // changedが呼ばれた.
  std::cout << "class_custom_presentation_model::changed()" << std::endl; // "class_custom_presentation_model::changed()"と出力.

  // 開始文字列と終了文字列の切り替え.
  class_custom_model *custom_model = dynamic_cast<class_custom_model *>(model_); // model_をclass_custom_modelポインタにダイナミックキャスト.
  if (custom_model != NULL){ // ダイナミックキャスト成功.
    int result = custom_model->get_result(); // custom_modelから計算結果resultを取得.
    if (result >= 0){ // 0以上.
      start_str_ = "("; // start_str_を"("にする.
      end_str_ = ")"; // end_str_を")"にする.
      std::cout << "()" << std::endl; // "()"を表示.
    }
    else{ // 0未満.
      start_str_ = "<"; // start_str_を"<"にする.
      end_str_ = ">"; // end_str_を">"にする.
      std::cout << "<>" << std::endl; // "<>"を表示.
    }
  }

  // 基底クラスを呼ぶ.
  class_presentation_model::changed(); // class_presentation_model::changedを呼ぶ.

}

// メンバ関数set_custom_view
void class_custom_presentation_model::set_custom_view(class_custom_view *custom_view){

  // custom_viewにも自身(this)をセット.
  custom_view->set_custom_presentation_model(this); // custom_view->set_custom_presentation_modelにthisをセット.

  // viewのセット.
  class_presentation_model::set_view(custom_view); // class_presentation_model::set_viewでcustom_viewをセット.

}

// メンバ関数get_start_str
std::string class_custom_presentation_model::get_start_str(){

  // 開始文字列を返す.
  return start_str_; // start_str_を返す.

}

// メンバ関数get_end_str
std::string class_custom_presentation_model::get_end_str(){

  // 終了文字列を返す.
  return end_str_; // end_str_を返す.

}

// メンバ関数get_x
int class_custom_presentation_model::get_x(){

  // custom_modelからxを取得.
  class_custom_model *custom_model = dynamic_cast<class_custom_model *>(model_); // model_をclass_custom_modelポインタにダイナミックキャスト.
  if (custom_model != NULL){ // ダイナミックキャスト成功.
    return custom_model->get_x(); // custom_model->get_xの値を返す.
  }
  else{ // 失敗.
    return 0; // 0を返す.
  }

}

// メンバ関数get_y
int class_custom_presentation_model::get_y(){

  // custom_modelからyを取得.
  class_custom_model *custom_model = dynamic_cast<class_custom_model *>(model_); // model_をclass_custom_modelポインタにダイナミックキャスト.
  if (custom_model != NULL){ // ダイナミックキャスト成功.
    return custom_model->get_y(); // custom_model->get_yの値を返す.
  }
  else{ // 失敗.
    return 0; // 0を返す.
  }

}

// メンバ関数get_result
int class_custom_presentation_model::get_result(){

  // custom_modelからresultを取得.
  class_custom_model *custom_model = dynamic_cast<class_custom_model *>(model_); // model_をclass_custom_modelポインタにダイナミックキャスト.
  if (custom_model != NULL){ // ダイナミックキャスト成功.
    return custom_model->get_result(); // custom_model->get_resultの値を返す.
  }
  else{ // 失敗.
    return 0; // 0を返す.
  }

}
