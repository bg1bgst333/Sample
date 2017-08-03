// 二重インクルード防止
#ifndef __MANAGER_H_
#define __MANAGER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "mediator.h" // interface_mediator

// クラスclass_manager
class class_manager : public interface_mediator{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<interface_member *> list_; // メンバリストlist_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_manager(){}; // コンストラクタclass_manager
    virtual ~class_manager(){}; // デストラクタ~class_manager
    // メンバ関数
    virtual void add(interface_member *member); // メンバ関数add
    virtual void changed(interface_member *member); // メンバ関数changed

};

#endif  
