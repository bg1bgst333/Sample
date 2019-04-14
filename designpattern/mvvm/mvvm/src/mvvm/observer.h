// 二重インクルード防止
#ifndef __OBSERVER_H_
#define __OBSERVER_H_

// 独自のヘッダ
#include "subject.h" // interface_subject

// 前方宣言
class interface_subject;

// インターフェースinterface_observer
class interface_observer{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_observer(){}; // コンストラクタinterface_observer
    virtual ~interface_observer(){}; // デストラクタ~interface_observer
    // メンバ関数
    virtual void set_subject(interface_subject *subject) = 0; // 純粋仮想関数set_subject
    //virtual void changed() = 0; // 純粋仮想関数changed
    virtual void changed(interface_subject *subject) = 0; // 純粋仮想関数changed

};

#endif 
