// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view
#include "custom_presentation_model.h" // class_custom_presentation_model

// 前方宣言
class class_custom_presentation_model;

// クラスclass_custom_view
class class_custom_view : public class_view{

  // 公開メンバ
  public:

    // 公開メンバ変数
    int x_; // int型変数x_.
    int y_; // int型変数y_.
    int result_; // int型変数result_.

    // 公開メンバ関数
    // メンバ関数
    virtual void notify(); // メンバ関数notify
    virtual void changed(); // メンバ関数changed
    virtual void set_custom_presentation_model(class_custom_presentation_model *custom_presentation_model); // メンバ関数set_custom_presentation_model

};

#endif
