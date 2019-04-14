// 二重インクルード防止
#ifndef __BUTTON_H_
#define __BUTTON_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "member.h" // interface_member
#include "mediator.h" // interface_mediator

// クラスclass_button
class class_button : public interface_member{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_mediator *mediator_; // interface_mediatorポインタmediator_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_button(){

      // メンバの初期化
      mediator_ = NULL; // mediator_をNULLで初期化.

    }
    virtual ~class_button(){};
    // メンバ関数
    virtual void set_mediator(interface_mediator *mediator){ // メンバ関数set_mediator

      // メンバにセット.
      mediator_ = mediator; // mediator_にmediatorをセット.

    }
    virtual void notify(){ // メンバ関数notify

      // mediator_に通知.
      if (mediator_ != NULL){ // NULLでなければ.
        mediator_->changed(this); // mediator_->changedにthisを渡す.
      }

    }

};

#endif
