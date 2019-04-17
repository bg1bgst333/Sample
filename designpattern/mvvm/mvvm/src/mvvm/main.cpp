// ヘッダのインクルード
// 独自のヘッダ
#include "custom_view.h" // class_custom_view

// main関数
int main(){

  // カスタムビューの生成
  class_custom_view *custom_view_ptr = new class_custom_view(); // class_custom_viewの生成.

  // カスタムビューの初期化
  custom_view_ptr->init("-", "-", "-"); // custom_view_ptr->initで"-", "-", "-"をセット.

  // カスタムビューの出力
  custom_view_ptr->print(); // custom_view_ptr->printで内容を出力.

  // 値の変更.
  custom_view_ptr->set_values("ABCDE", "XYZ", "-");

  // カスタムビューの出力
  custom_view_ptr->print(); // custom_view_ptr->printで内容を出力.

  // 値の変更.
  custom_view_ptr->set_values("abc", "xyz", "-");

  // カスタムビューの出力
  custom_view_ptr->print(); // custom_view_ptr->printで内容を出力.

  // カスタムビューの削除
  delete custom_view_ptr; // custom_view_ptrの削除.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
