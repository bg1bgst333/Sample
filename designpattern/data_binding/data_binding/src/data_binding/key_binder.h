// 二重インクルード防止
#ifndef __KEY_BINDER_H_
#define __KEY_BINDER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <map> // std::map
#include <list> // std::list
// 独自のヘッダ
#include "binder.h" // interface_binder

// テンプレートクラスclass_key_binder<K>
template <typename K> class class_key_binder : public interface_binder<K>{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::map<K *, std::list<interface_binder<K> *>>bindings_; // Kのポインタをキーとするマップbindings_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_key_binder(){}; // コンストラクタclass_key_binder.
    virtual ~class_key_binder(){}; // デストラクタ~class_key_binder.
    // メンバ関数
    virtual bool bind(interface_binder<K> *b, K *key){ // メンバ関数bind

      // マップに登録.
      bindings_[key].push_back(b); // keyをキー, bを値としてbindings_に登録.

      // true.
      return true; // trueを返す.

    }

};

#endif
