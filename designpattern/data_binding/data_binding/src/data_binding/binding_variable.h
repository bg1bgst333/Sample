// 二重インクルード防止
#ifndef __BINDING_VARIABLE_H_
#define __BINDING_VARIABLE_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "setter.h" // class_setter
#include "getter.h" // class_getter
#include "comparator.h" // class_comparator
#include "binder.h" // interface_binder

// テンプレートクラスclass_binding_variable<K, V>
template <typename K, typename V> class class_binding_variable : public interface_binder<K>{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<K *> key_list_; // K型のポインタをキーとするリストkey_list_.
    V value_; // V型の値value_.
    class_setter<K, V> &setter_; // セッターの参照setter_.
    class_getter<K, V> &getter_; // ゲッターの参照getter_.
    class_comparator<V> &comparator_; // コンパレーターの参照comparator_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_binding_variable(V value, class_setter<K, V> &setter, class_getter<K, V> &getter, class_comparator<V> &comparator) : setter_(setter), getter_(getter), comparator_(comparator){ // コンストラクタclass_binding_variable.(value_以外のメンバを初期化.)

      // メンバにセット.
      value_ = value; // value_にvalueを代入.

    }
    virtual ~class_binding_variable(){} // デストラクタ~class_binding_variable.

};
 
#endif
