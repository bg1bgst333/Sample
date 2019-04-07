// 二重インクルード防止
#ifndef __KEY_BINDER_H_
#define __KEY_BINDER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
#include <map> // std::map
// 独自のヘッダ
#include "binder.h" // interface_binder
#include "mediator.h" // interface_mediator
#include "member.h" // interface_member

// テンプレートクラスclass_key_binder<K>
template <typename K> class class_key_binder : public interface_binder<K>, public interface_mediator{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::map<K *, std::list<interface_binder<K>*>>bindings_; // Kのポインタをキーとするマップbindings_.
    
  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_key_binder(){}; // コンストラクタclass_key_binder.
    virtual ~class_key_binder(){}; // デストラクタ~class_key_binder.
    // メンバ関数
    virtual bool bind(interface_binder<K> *b, K *key){ // メンバ関数bind

      // keyがこちらをメディエイター登録.
      key->set_mediator(this); // key->set_mediatorでthisを登録.

      // b側でもbind.
      b->bind(b, key); // bとkeyをb->bindに渡してバインド.

      // マップに登録.
      bindings_[key].push_back(b); // keyをキー, bを値としてbindings_に登録.

      // true.
      return true; // trueを返す.

    }
    virtual void update(K *key){ // メンバ関数update

      // ここは今回は不要.

    }
    virtual void set_member(interface_member *member){ // メンバ関数set_member

      // ここは今回は不要.

    }
    virtual void add(interface_member *member){ // メンバ関数add

      // ここは今回は不要.

    }
    virtual void changed(interface_member *member){ // メンバ関数changed

      // マップの走査.
      typename std::map<K *, std::list<interface_binder<K> *>>::iterator it = bindings_.begin(); // イテレータitを初期化.(ここのtypenameは付けないとビルドエラー.)
      while(it != bindings_.end()){ // 終わるまで.

        // リストの走査.
        typename std::list<interface_binder<K> *>::iterator list_it = it->second.begin(); // イテレータlist_itを初期化.(ここのtypenameは付けないとビルドエラー.)
        while(list_it != it->second.end()){ // 終わるまで.

          // 更新.
          (*list_it)->update((K *)member); // 各要素のupdate.

          // イテレータを進める.
          list_it++; // list_itを増やす.

        }

        // イテレータを進める.
        it++; // itを増やす.

      }

    }

};

#endif
