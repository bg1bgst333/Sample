// 二重インクルード防止
#ifndef __OBSERVER_H_
#define __OBSERVER_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "member.h" // interface_member

// 前方宣言
class interface_member;

// インターフェースinterface_observer
class interface_observer{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_observer(){}; // コンストラクタinterface_observer
    virtual ~interface_observer(){}; // デストラクタinterface_observer
    // メンバ関数
    virtual void add(interface_member *member) = 0; // 純粋仮想関数add
    virtual void changed(interface_member *member) = 0; // 純粋仮想関数changed

};

#endif
