// ヘッダのインクルード
#ifndef __CUSTOM_PRESENTATION_MODEL_H_
#define __CUSTOM_PRESENTATION_MODEL_H_

// 既定のヘッダ
#include <string> // std::string
// 独自のヘッダ
#include "presentation_model.h" // class_presentation_model
#include "custom_view.h" // class_custom_view

// クラスclass_custom_presentation_model
class class_custom_presentation_model : public class_presentation_model{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string start_str_; // 開始文字列.
    std::string end_str_; // 終了文字列.

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual void changed(); // メンバ関数changed
    void set_custom_view(class_custom_view *custom_view); // メンバ関数set_custom_view

};

#endif
