// ヘッダのインクルード
// 独自のヘッダ
#include "controller.h" // class_controller
#include "view.h" // class_view
#include "model.h" // class_model
#include "presentation_model.h" // class_presentation_model

// main関数
int main(){

  // オブジェクトの生成.
  class_controller *controller_ptr = new class_controller(); // class_controllerオブジェクトの生成.
  class_view *view_ptr = new class_view(); // class_viewオブジェクトの生成.
  class_model *model_ptr = new class_model(); // class_modelオブジェクトの生成.
  class_presentation_model *presentation_model_ptr = new class_presentation_model(); // class_presentation_modelオブジェクトの生成.

  // コントローラにビューをセット.
  controller_ptr->set_view(view_ptr); // controller_ptr->set_viewでview_ptrをセット.

  // プレゼンテーションモデルにビューをセット.
  presentation_model_ptr->set_view(view_ptr); // presentation_model_ptr->set_viewでview_ptrをセット.

  // モデルにプレゼンテーションモデルをセット.
  model_ptr->set_presentation_model(presentation_model_ptr); // model_ptr->set_presentation_modelでpresentation_model_ptrをセット.

  // コントローラにモデルをセット.
  controller_ptr->set_model(model_ptr); // controller_ptr->set_modelでmodel_ptrをセット.

  // 通知.
  view_ptr->notify(); // view_ptr->notifyで通知する.

  // オブジェクトの破棄.
  delete controller_ptr; // deleteでcontroller_ptrを解放.
  delete view_ptr; // deleteでview_ptrを解放.
  delete model_ptr; // deleteでmodel_ptrを解放.
  delete presentation_model_ptr; // deleteでpresentation_model_ptrを解放.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
