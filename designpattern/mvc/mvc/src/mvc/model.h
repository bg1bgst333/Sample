// 二重インクルード
#ifndef __MODEL_H_
#define __MODEL_H_

// 独自のヘッダ
#include "subject.h" // interface_subject
#include "observer.h" // interface_observer

// クラスclass_model
class class_model : public interface_subject{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_observer *observer_; // interface_observerポインタobserver_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_model(){}; // コンストラクタclass_model
    virtual ~class_model(){}; // デストラクタ~class_model
    // メンバ関数
    virtual void set_observer(interface_observer *observer); // メンバ関数set_observer
    virtual void notify(); // メンバ関数notify

};

#endif
