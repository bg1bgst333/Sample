// ヘッダのインクルード
// 独自のヘッダ
#include "view.h" // class_view
#include "presenter.h" // class_presenter
#include "model.h" // class_model

// main関数
int main(){

  // オブジェクトの生成.
  class_view *view_ptr = new class_view(); // class_viewオブジェクトの生成.
  class_presenter *presenter_ptr = new class_presenter(); // class_presenterオブジェクトの生成.
  class_model *model_ptr = new class_model(); // class_modelオブジェクトの生成.

  // プレゼンターにビューをセット.
  presenter_ptr->set_view(view_ptr); // presenter_ptr->set_viewでview_ptrをセット.

  // プレゼンターにモデルをセット.
  presenter_ptr->set_model(model_ptr); // presenter_ptr->set_modelでmodel_ptrをセット.

  // 通知.
  view_ptr->notify(); // view_ptr->notifyで通知.

  // オブジェクトの破棄.
  delete view_ptr; // deleteでview_ptrを解放.
  delete presenter_ptr; // deleteでpresenter_ptrを解放.
  delete model_ptr; // deleteでmodel_ptrを解放.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
