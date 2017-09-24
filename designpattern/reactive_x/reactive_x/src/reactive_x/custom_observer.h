// 二重インクルード防止
#ifndef __CUSTOM_OBSERVER_H_
#define __CUSTOM_OBSERVER_H_

// 独自のヘッダ
#include "observer.h" // interface_observer

// クラスclass_custom_observer
class class_custom_observer : public interface_observer{

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void completed(); // メンバ関数completed
    virtual void error(); // メンバ関数error
    virtual void next(std::string value); // メンバ関数next

};

#endif
