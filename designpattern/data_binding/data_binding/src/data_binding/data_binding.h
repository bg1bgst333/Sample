// 二重インクルード防止
#ifndef __DATA_BINDING_H_
#define __DATA_BINDING_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "mediator.h" // interface_mediator
#include "member.h" // interface_member

// テンプレートクラスclass_data_binding<T>
template <typename T> class class_data_binding : public interface_mediator{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<T *>list_; // メンバリストlist_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ.
    class_data_binding(){ // コンストラクタclass_data_binding

      // メンバの初期化.
      list_.clear(); // list_.clearでクリア.

    }
    virtual ~class_data_binding(){ // デストラクタ~class_data_binding

      // メンバの終了処理.
      list_.clear(); // list_.clearでクリア.

    }
    virtual void add(interface_member *member){ // メンバ関数add

      // リストメンバの追加.
      member->set_mediator(this); // memberのメディエイターとしてthisをセット.
      list_.push_back((T*)member); // list_.push_backでmemberを追加.

    } 
    virtual void changed(interface_member *member){ // メンバ関数changed

      // 全てのmemberの値を更新.
      typename std::list<T*>::iterator itor = list_.begin(); // itorを先頭にセット.
      while(itor != list_.end()){ // 末尾まで繰り返す.
        if (*itor != member){ // 変更されたメンバー以外.
          std::string src = ((T*)member)->get_value(); // 変更元
          std::string target = (*itor)->get_value(); // 変更先
          if (src != target){ // 違う.
            (*itor)->set_value(src); // 変更.
          }
        }
        itor++; // itorを進める.
      }

    }

};

#endif
