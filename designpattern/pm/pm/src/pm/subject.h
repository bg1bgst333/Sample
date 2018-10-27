// 二重インクルード防止
#ifndef __SUBJECT_H_
#define __SUBJECT_H_

// 独自のヘッダ
#include "observer.h" // interface_observer

// 前方宣言
class interface_observer;

// インターフェースinterface_subject
class interface_subject{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_subject(){}; // コンストラクタinterface_subject
    virtual ~interface_subject(){}; // デストラクタ~interface_subject
    // メンバ関数
    virtual void set_observer(interface_observer *observer) = 0; // 純粋仮想関数set_observer
    virtual void notify() = 0; // 純粋仮想関数notify

};

#endif
