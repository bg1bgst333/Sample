// 二重インクルード防止
#ifndef __BINDING_COMMAND_H_
#define __BINDING_COMMAND_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "action.h" // class_action
#include "binder.h" // interface_binder

// テンプレートクラスclass_binding_command<K>
template <typename K> class class_binding_command : public interface_binder<K>{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<K *> key_list_; // K型のポインタをキーとするリストkey_list_.
    class_action<K> &action_; // アクションの参照action_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_binding_command(class_action<K> &action) : action_(action){ // コンストラクタclass_binding_command.

      // メンバにセット.
      action_ = action; // action_にactionをセット.

    }
    virtual ~class_binding_command(){}; // デストラクタ~class_binding_command.
    // メンバ関数
    virtual bool bind(interface_binder<K> *binder, K *key){ // メンバ関数bind

      // キーを追加.
      key_list_.push_back(key); // key_list_にkeyを追加.

      // true.
      return true; // trueを返す.

    }
    virtual void update(K *key){ // メンバ関数update

      // 更新.
      std::cout << "binding_command_update" << std::endl; // "binding_command_update"を出力.

      // on_commandの実行.
      on_command(key); // on_commandにkeyを渡す.

    }
    virtual void on_command(K *key){ // メンバ関数on_command

      // action_を実行.
      action_(key); // action_にkeyを渡して実行.

    }

};

#endif
