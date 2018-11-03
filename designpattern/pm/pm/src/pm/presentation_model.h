// ヘッダのインクルード
#ifndef __PRESENTATION_MODEL_H_
#define __PRESENTATION_MODEL_H_

// 独自のヘッダ
#include "observer.h" // interface_observer
#include "subject.h" // interface_subject
#include "view.h" // class_view
#include "model.h" // class_model

// 前方宣言
class class_model;
class class_view;

// クラスclass_presentation_model
class class_presentation_model : public interface_observer, public interface_subject{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_subject *subject_; // interface_subjectポインタsubject_.
    interface_observer *observer_; // interface_observerポインタobserver_.

  // 被保護メンバ
  protected:

    // 被保護メンバ変数
    class_model *model_; // class_modelポインタmodel_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_presentation_model(){}; // コンストラクタclass_presentation_model
    virtual ~class_presentation_model(){}; // デストラクタ~class_presentation_model
    // メンバ関数
    virtual void set_subject(interface_subject *subject); // メンバ関数set_subject
    virtual void changed(); // メンバ関数changed
    virtual void set_observer(interface_observer *observer); // メンバ関数set_observer
    virtual void notify(); // メンバ関数notify
    void set_view(class_view *view); // メンバ関数set_view
    void set_model(class_model *model); // メンバ関数set_model

};

#endif
