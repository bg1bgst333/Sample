// 二重インクルード防止
#ifndef __CUSTOM_VIEW_H_
#define __CUSTOM_VIEW_H_

// 独自のヘッダ
#include "view.h" // class_view
#include "custom_model.h" // class_custom_model

// クラスclass_custom_view
class class_custom_view : public class_view{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_custom_model *custom_model_; // class_custom_modelポインタcustom_model_.

  // 公開メンバ
  public:

    // 公開メンバ変数
    int x_; // int型変数x_.
    int y_; // int型変数y_.
    int result_; // int型変数result_.

    // 公開メンバ関数
    void set_custom_model(class_custom_model *custom_model); // メンバ関数set_custom_model
    virtual void changed(); // メンバ関数changed

};

#endif
