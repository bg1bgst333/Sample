// ヘッダのインクルード
// 独自のヘッダ
#include "controller.h" // class_controller
#include "view.h" // class_view

// main関数
int main(){

  // オブジェクトの生成.
  class_controller *controller_ptr = new class_controller(); // class_controllerオブジェクトの生成.
  class_view *view_ptr = new class_view(); // class_viewオブジェクトの生成.

  // コントローラにビューをセット.
  controller_ptr->set_view(view_ptr); // controller_ptr->set_viewでview_ptrをcontroller_ptrにセット.

  // 試しに通知してみる.
  view_ptr->notify(); // view_ptr->notifyで通知する.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
