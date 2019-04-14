// 二重インクルード防止
#ifndef __VIEW_MODEL_H_
#define __VIEW_MODEL_H_

// 独自のヘッダ
#include "binding_variable.h" // class_binding_variable
#include "input_form.h" // class_input_form
#include "key_binder.h" // class_key_binder
#include "setter.h" // class_setter
#include "getter.h" // class_getter
#include "comparator.h" // class_comparator
#include "binding_command.h" // class_binding_command
#include "action.h" // class_action
#include "button.h" // class_button

// テンプレートクラスclass_view_model<K, V>
template <typename K, typename V>class class_view_model{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_setter<K, V> setter_; // セッター.
    class_getter<K, V> getter_; // ゲッター.
    class_comparator<V> comparator_; // コンパレーター.
    class_action<class_button> action_; // アクション.

  // 公開メンバ
  public:

    // 公開メンバ変数
    class_binding_variable<K, V> *binding_str1_ptr_; // binding_str1のポインタ.
    class_binding_variable<K, V> *binding_str2_ptr_; // binding_str2のポインタ.
    class_binding_variable<K, V> *binding_str3_ptr_; // binding_str3のポインタ.
    class_binding_command<class_button> *binding_command1_ptr_; // binding_command1のポインタ.
    // コンストラクタとデストラクタ
    class_view_model(){ // コンストラクタ

    }
    virtual ~class_view_model(){ // デストラクタ

    }
    // 公開メンバ関数
    void init(){ // 初期化メンバ関数init

      // バインディング変数の初期化.
      binding_str1_ptr_ = new class_binding_variable<K, V>("str1", setter_, getter_, comparator_); // str1に"str1"をセット.
      binding_str2_ptr_ = new class_binding_variable<K, V>("str2", setter_, getter_, comparator_); // str2に"str2"をセット.
      binding_str3_ptr_ = new class_binding_variable<K, V>("str3", setter_, getter_, comparator_); // str3に"str3"をセット.
      binding_command1_ptr_ = new class_binding_command<class_button>(action_); // command1にaction_をセット.

    }
    void exit(){ // 終了処理メンバ関数exit

      // バインディング変数の終了処理.
      delete binding_command1_ptr_; // command1の削除.
      delete binding_str1_ptr_; // str1の削除.
      delete binding_str2_ptr_; // str2の削除.
      delete binding_str3_ptr_; // str3の削除.

    }

};

#endif
