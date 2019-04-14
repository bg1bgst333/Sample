// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// メンバ関数init
void class_custom_view::init(std::string str1, std::string str2, std::string str3){

  // フォームの初期化
  form1_ptr_ = new class_input_form<std::string>(str1); // form1を生成し, str1で初期化.
  form2_ptr_ = new class_input_form<std::string>(str2); // form2を生成し, str2で初期化.
  form3_ptr_ = new class_input_form<std::string>(str3); // form3を生成し, str3で初期化.

  // ビューモデルの初期化
  view_model_ptr_ = new class_view_model<class_input_form<std::string>, std::string>(); // class_view_modelの生成.
  view_model_ptr_->init(); // 初期化.

  // バインド
  binder_.bind(view_model_ptr_->binding_str1_ptr_, form1_ptr_); // str1とform1をbind.
  binder_.bind(view_model_ptr_->binding_str2_ptr_, form2_ptr_); // str2とform2をbind.
  binder_.bind(view_model_ptr_->binding_str3_ptr_, form3_ptr_); // str3とform3をbind.

}

// メンバ関数print
void class_custom_view::print(){

  // フォームの値を出力.
  form1_ptr_->print_value(); // form1の値を出力.
  form2_ptr_->print_value(); // form2の値を出力.
  form3_ptr_->print_value(); // form3の値を出力.

}

// メンバ関数exit
void class_custom_view::exit(){

  // ビューモデルの終了処理
  view_model_ptr_->exit(); // 終了処理.
  delete view_model_ptr_; // 削除.

  // フォームの終了処理
  delete form1_ptr_; // form1_ptr_を削除.
  delete form2_ptr_; // form2_ptr_を削除.
  delete form3_ptr_; // form3_ptr_を削除.

}
