// 二重インクルード防止
#ifndef __CUSTOM_MODEL_H_
#define __CUSTOM_MODEL_H_

// 独自のヘッダ
#include "model.h" // class_model
#include "custom_presentation_model.h" // class_custom_presentation_model

// クラスclass_custom_model
class class_custom_model : public class_model{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    int x_; // int型変数x_.
    int y_; // int型変数y_.
    int result_; // int型変数result_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    void func(int x, int y); // メンバ関数func(int x, int y).
    int get_x(); // メンバ関数get_x.
    int get_y(); // メンバ関数get_y.
    int get_result(); // メンバ関数get_result.
    void set_custom_presentation_model(class_custom_presentation_model *custom_presentation_model); // メンバ関数set_custom_presentation_model

};

#endif
