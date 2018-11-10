// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view
#include "custom_presenter.h" // class_custom_presenter

// 前方宣言
class class_custom_presenter;

// クラスclass_custom_view
class class_custom_view : public class_view{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_custom_presenter *custom_presenter_; // custom_presenter_ポインタ.

  // 公開メンバ
  public:

    // 公開メンバ変数
    int x_; // int型変数x_.
    int y_; // int型変数y_.
    int result_; // int型変数result_.

    // 公開メンバ関数
    // メンバ関数
    virtual void notify(); // メンバ関数notify
    void set_custom_presenter(class_custom_presenter *custom_presenter); // メンバ関数set_custom_presenter
    virtual void changed(interface_subject *subject); // メンバ関数changed

};

#endif
