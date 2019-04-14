// 二重インクルード防止
#ifndef __VIEW_H_
#define __VIEW_H_

// 独自のヘッダ
#include "subject.h" // interface_subject
#include "observer.h" // interface_observer

// クラスclass_view
class class_view : public interface_subject, public interface_observer{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_observer *observer_; // interface_observerポインタobserver_.
    interface_subject *subject_; // interface_subjectポインタsubject_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_view(){}; // コンストラクタclass_view
    virtual ~class_view(){}; // デストラクタ~class_view
    // メンバ関数
    virtual void set_observer(interface_observer *observer); // メンバ関数set_observer
    virtual void notify(); // メンバ関数notify
    virtual void set_subject(interface_subject *subject); // メンバ関数set_subject
    virtual void changed(interface_subject *subject); // メンバ関数changed

};

#endif
