// ヘッダのインクルード
// 独自のヘッダ
#include "custom_controller.h" // class_custom_controller
#include "custom_view.h" // class_custom_view

// main関数
int main(){

  // オブジェクトの生成.
  class_custom_controller *custom_controller_ptr = new class_custom_controller(); // class_custom_controllerオブジェクトの生成.
  class_custom_view *custom_view_ptr = new class_custom_view(); // class_custom_viewオブジェクトの生成.

  // カスタムコントローラにカスタムビューをセット.
  custom_controller_ptr->set_custom_view(custom_view_ptr); // custom_controller_ptr->set_custom_viewでcustom_view_ptrをcustom_controller_ptrにセット.

  // カスタムビューに値をセット.
  custom_view_ptr->x = 1; // custom_view_ptr->xに1を代入.
  custom_view_ptr->y = 2; // custom_view_ptr->yに2を代入.
  custom_view_ptr->result = 0; // custom_view_ptr->resultに0を代入.

  // 値の確定.
  custom_view_ptr->notify(); // custom_view_ptr->notifyで値が確定したことを通知.

  // オブジェクトの破棄.
  delete custom_controller_ptr; // deleteでcustom_controller_ptrを解放.
  delete custom_view_ptr; // deleteでcustom_view_ptrを解放.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
