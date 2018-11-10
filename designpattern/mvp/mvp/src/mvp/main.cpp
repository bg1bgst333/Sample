// ヘッダのインクルード
// 独自のヘッダ
#include "custom_view.h" // class_custom_view
#include "custom_presenter.h" // class_custom_presenter
#include "custom_model.h" // class_custom_model

// main関数
int main(){

  // オブジェクトの生成.
  class_custom_view *custom_view_ptr = new class_custom_view(); // class_custom_viewオブジェクトの生成.
  class_custom_presenter *custom_presenter_ptr = new class_custom_presenter(); // class_custom_presenterオブジェクトの生成.
  class_custom_model *custom_model_ptr = new class_custom_model(); // class_custom_modelオブジェクトの生成.

  // カスタムビューに値をセット.
  custom_view_ptr->x_ = 1; // custom_view_ptr->x_に1を代入.
  custom_view_ptr->y_ = 2; // custom_view_ptr->y_に2を代入.
  custom_view_ptr->result_ = 0; // custom_view_ptr->result_に0を代入.

  // カスタムプレゼンターにカスタムビューをセット.
  custom_presenter_ptr->set_custom_view(custom_view_ptr); // custom_presenter_ptr->set_custom_viewでcustom_view_ptrをセット.

  // カスタムプレゼンターにカスタムモデルをセット.
  custom_presenter_ptr->set_custom_model(custom_model_ptr); // custom_presenter_ptr->set_custom_modelでcustom_model_ptrをセット.

  // 値の確定.
  custom_view_ptr->notify(); // custom_view_ptr->notifyで値が確定したことを通知.

  // オブジェクトの破棄.
  delete custom_view_ptr; // deleteでcustom_view_ptrを解放.
  delete custom_presenter_ptr; // deleteでcustom_presenter_ptrを解放.
  delete custom_model_ptr; // deleteでcustom_model_ptrを解放.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
