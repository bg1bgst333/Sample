// 二重インクルード防止
#ifndef __CUSTOM_PRESENTER_H_
#define __CUSTOM_PRESENTER_H_

// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "presenter.h" // class_presenter
#include "custom_view.h" // class_custom_view
#include "custom_model.h" // class_custom_model

// クラスclass_custom_presenter
class class_custom_presenter : public class_presenter{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    class_custom_view *custom_view_; // class_custom_viewポインタcustom_view_.
    class_custom_model *custom_model_; // class_custom_modelポインタcustom_model_.
    std::string start_str_; // 開始文字列
    std::string end_str_; // 終了文字列

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void changed(interface_subject *subject); // メンバ関数changed
    void set_custom_view(class_custom_view *custom_view); // メンバ関数set_custom_view
    void set_custom_model(class_custom_model *custom_model); // メンバ関数set_custom_model
};

#endif
