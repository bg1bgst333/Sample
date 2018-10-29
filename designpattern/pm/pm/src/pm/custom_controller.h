// 二重インクルード防止
#ifndef __CUSTOM_CONTROLLER_H_
#define __CUSTOM_CONTROLLER_H_

// 独自のヘッダ
#include "controller.h" // class_controller
#include "custom_view.h" // class_custom_view
#include "custom_model.h" // class_custom_model

// クラスclass_custom_controller
class class_custom_controller : public class_controller{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_custom_view *custom_view_; // class_custom_viewポインタcustom_view_.
    class_custom_model *custom_model_; // class_custom_modelポインタcustom_model_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void changed(); // メンバ関数changed
    void set_custom_view(class_custom_view *custom_view); // メンバ関数set_custom_view
    void set_custom_model(class_custom_model *custom_model); // メンバ関数set_custom_model

};

#endif
