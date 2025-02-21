// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view
#include "input_form.h" // class_input_form
#include "button.h" // class_button
#include "view_model.h" // class_view_model
#include "key_binder.h" // class_key_binder

// 前方宣言
class class_custom_presenter;

// クラスclass_custom_view
class class_custom_view : public class_view{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_input_form<std::string> *form1_ptr_; // form1
    class_input_form<std::string> *form2_ptr_; // form2
    class_input_form<std::string> *form3_ptr_; // form3
    class_button *button1_ptr_; // button1
    class_view_model<class_input_form<std::string>, std::string> *view_model_ptr_; // ViewModelポインタ.
    class_key_binder<class_input_form<std::string>> binder_; // バインダー.
    class_key_binder<class_button> button_binder_; // ボタンバインダー.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_custom_view(){ // コンストラクタ

      // 初期化.
      view_model_ptr_ = NULL; // NULLで初期化.

    }

    // メンバ関数
    void init(std::string str1, std::string str2, std::string str3); // メンバ関数init
    void print(); // メンバ関数print
    void set_values(std::string form1_str, std::string form2_str, std::string form3_str); // メンバ関数set_values
    void exit(); // メンバ関数exit

};

#endif
