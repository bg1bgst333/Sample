// ヘッダのインクルード
// 独自のヘッダ
#include "print_proc.h" // class_print_proc

// メンバの定義
// メンバ関数template_method
void class_print_proc::template_method(){

  // 前処理
  if (!begin_print()){ // begin_printがfalseなら.
    return;
  }

  // 本処理
  if (!print()){ // printがfalseなら.
    return;
  }

  // 後処理
  if (!end_print()){ // end_printがfalseなら.
    return;
  }

} 
