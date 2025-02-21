// 二重インクルード防止
#ifndef __INPUT_FORM_H_
#define __INPUT_FORM_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "member.h" // interface_member
#include "mediator.h" // interface_mediator

// テンプレートクラスclass_input_form<T>
template <typename T> class class_input_form : public interface_member{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    T value_; // T型の値value_
    interface_mediator *mediator_; // interface_mediatorポインタmediator_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_input_form(T value){ // コンストラクタclass_input_form

      // メンバの初期化
      value_ = value; // value_はvalueで初期化.
      mediator_ = NULL; // mediator_をNULLで初期化.

    }
    virtual ~class_input_form(){}; // デストラクタ~class_input_form
    // メンバ関数
    virtual void set_value(T value){ // メンバ関数set_value

      // メンバにセット
      value_ = value; // value_にvalueをセット.

      // メディエイターに通知.
      notify(); // notifyで通知.      

    }
    virtual T get_value(){ // メンバ関数get_value

      // 値を返す.
      return value_; // value_を返す.

    }
    virtual void print_value(){ // メンバ関数print_value

      // 値を出力.
      std::cout << "value_ = " << value_ << std::endl; // value_の値を出力.

    }
    virtual void set_mediator(interface_mediator *mediator){ // メンバ関数set_mediator

      // メンバにセット.
      mediator_ = mediator; // mediator_にmediatorをセット.

    }
    virtual void notify(){ // メンバ関数notify

      // mediator_に通知.
      if (mediator_ != NULL){ // NULLでなければ.
        mediator_->changed(this); // mediator_->changedにthisを渡す.
      }

    }

};

#endif
