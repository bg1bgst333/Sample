// 二重インクルード防止
#ifndef __CUSTOM_OBSERVABLE_H_
#define __CUSTOM_OBSERVABLE_H_

// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "observable.h" // interface_observable

// クラスclass_custom_observable
class class_custom_observable : public interface_observable{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<interface_observer *> observers_; // オブザーバーリストobservers_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void subscribe(interface_observer *observer); // メンバ関数subscribe
    virtual void notify(std::string value); // メンバ関数notify

};

#endif
