// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view
#include "input_form.h" // class_input_form

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

  // 公開メンバ
  public:

    // 公開メンバ関数
    // メンバ関数
    void init(std::string str1, std::string str2, std::string str3); // メンバ関数init
    void print(); // メンバ関数print
    void exit(); // メンバ関数exit

};

#endif
