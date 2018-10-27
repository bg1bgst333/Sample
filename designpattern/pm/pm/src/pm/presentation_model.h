// ヘッダのインクルード
#ifndef __PRESENTATION_MODEL_H_
#define __PRESENTATION_MODEL_H_

// 独自のヘッダ
#include "observer.h" // interface_observer
#include "subject.h" // interface_subject

// クラスclass_presentation_model
class class_presentation_model : public interface_observer{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_subject *subject_; // interface_subjectポインタsubject_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_presentation_model(){}; // コンストラクタclass_presentation_model
    virtual ~class_presentation_model(){}; // デストラクタ~class_presentation_model
    // メンバ関数
    virtual void set_subject(interface_subject *subject); // メンバ関数set_subject
    virtual void changed(); // メンバ関数changed

};

#endif
