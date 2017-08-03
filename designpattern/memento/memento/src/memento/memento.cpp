// ヘッダのインクルード
// 独自のヘッダ
#include "memento.h" // class_memento

// メンバの定義
// メンバ関数set_value
void class_memento::set_value(int value){

  // メンバにセット.
  value_ = value; // valueをvalue_にセット.

}

// メンバ関数get_value
int class_memento::get_value() const{

  // 値を返す.
  return value_; // value_を返す.

}
