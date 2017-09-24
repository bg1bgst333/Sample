// 二重インクルード防止
#ifndef __OBSERVABLE_H_
#define __OBSERVABLE_H_

// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "observer.h" // interface_observer

class interface_observer;

// インターフェースinterface_observable
class interface_observable{

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void subscribe(interface_observer *observer) = 0; // 純粋仮想関数subscribe
    virtual void notify(std::string value) = 0; // 純粋仮想関数notify

};

#endif
