// 二重インクルード防止
#ifndef __MEMBER_H_
#define __MEMBER_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "mediator.h" // interface_mediator

// 前方宣言
class interface_mediator;

// インターフェースinterface_member
class interface_member{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_member(){}; // コンストラクタinterface_member
    virtual ~interface_member(){}; // デストラクタ~interface_member
    // メンバ関数
    virtual void set_mediator(interface_mediator *mediator) = 0; // 純粋仮想関数set_mediator

};

#endif
