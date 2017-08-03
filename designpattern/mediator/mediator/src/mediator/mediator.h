// 二重インクルード防止
#ifndef __MEDIATOR_H_
#define __MEDIATOR_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "member.h" // interface_member

// 前方宣言
class interface_member;

// インターフェースinterface_mediator
class interface_mediator{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_mediator(){}; // コンストラクタinterface_mediator
    virtual ~interface_mediator(){}; // デストラクタinterface_mediator
    // メンバ関数
    virtual void add(interface_member *member) = 0; // 純粋仮想関数add
    virtual void changed(interface_member *member) = 0; // 純粋仮想関数changed

};

#endif
