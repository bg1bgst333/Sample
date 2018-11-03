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

  // viewのセット.
  class_presentation_model::set_view(custom_view); // class_presentation_model::set_viewでcustom_viewをセット.

}
