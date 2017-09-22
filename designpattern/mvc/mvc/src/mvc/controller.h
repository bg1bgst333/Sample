// 二重インクルード防止
#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_

// 独自のヘッダ
#include "observer.h" // interface_observer
#include "subject.h" // interface_subject
#include "view.h" // class_view

// クラスclass_controller
class class_controller : public interface_observer{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_subject *subject_; // interface_subjectポインタsubject_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_controller(){}; // コンストラクタclass_controller
    virtual ~class_controller(){}; // デストラクタ~class_controller
    // メンバ関数
    virtual void set_subject(interface_subject *subject); // メンバ関数set_subject
    virtual void changed(); // メンバ関数changed
    virtual void set_view(class_view *view); // メンバ関数set_view

};

#endif
