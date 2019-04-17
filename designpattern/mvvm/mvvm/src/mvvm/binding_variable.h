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
      setter_ = setter; // setter_にsetterを代入.

    }
    virtual ~class_binding_variable(){} // デストラクタ~class_binding_variable.
    // メンバ関数
    virtual bool bind(interface_binder<K> *binder, K *key){ // メンバ関数bind

      // キーを追加.
      key_list_.push_back(key); // key_list_にkeyを追加.

      // セッターを実行.
      setter_(key, value_); // keyとvalue_を渡して, setter_を実行.

      // true.
      return true; // trueを返す.

    }
    virtual void update(K *key){ // メンバ関数update

      // 変更後の値を取得.
      value_ = getter_(key); // 値を取得.

      // リストの走査.
      typename std::list<K *>::iterator key_list_it = key_list_.begin(); // イテレータkey_list_itを初期化.
      while(key_list_it != key_list_.end()){ // 終わるまで.

        // 更新.
        if (comparator_(value_, getter_(*key_list_it))){ // trueなら更新.
          setter_(*key_list_it, value_); // key_list_itの指す要素の値をvalue_に更新.          
        }

        // イテレータを進める.
        key_list_it++; // key_list_itを増やす.

      }

    }
    virtual void set_value(V value){ // メンバ関数set_value

      // セッターを実行.
      value_ = value; // value_にvalueをセット.

      // リストの走査.
      typename std::list<K *>::iterator key_list_it = key_list_.begin(); // イテレータkey_list_itを初期化.
      while(key_list_it != key_list_.end()){ // 終わるまで.

        // 更新.
        if (comparator_(value_, getter_(*key_list_it))){ // trueなら更新.
          setter_(*key_list_it, value_); // key_list_itの指す要素の値をvalue_に更新.
        }

        // イテレータを進める.
        key_list_it++; // key_list_itを増やす.

      }

    }
    virtual V get_value(){ // メンバ関数get_value

      // 値を返す.
      return value_; // value_を返す.

    }

};
 
#endif
