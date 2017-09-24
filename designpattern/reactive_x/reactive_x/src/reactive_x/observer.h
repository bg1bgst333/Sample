// 二重インクルード防止
#ifndef __OBSERVER_H_
#define __OBSERVER_H_

// 既定のヘッダ
#include <string> // std:string
// 独自のヘッダ
#include "observable.h" // interface_observable

// インターフェースinterface_observer
class interface_observer{

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void completed() = 0; // 純粋仮想関数completed
    virtual void error() = 0; // 純粋仮想関数error
    virtual void next(std::string value) = 0; // 純粋仮想関数next

};

#endif
