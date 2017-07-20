// ヘッダのインクルード
// 独自のヘッダ
#include "iterator.h" // class_iterator

// メンバの定義
// コンストラクタ
class_iterator::class_iterator(class_array *array){

  // 現在位置を先頭にする.
  current_ = 0; // current_を0にセット.

  // 引数をメンバにセット.
  array_ = array; // arrayをarray_にセット.

}

// メンバ関数current
class_element *class_iterator::current(){

  // 現在の要素を返す.
  if (current_ < array_->get_size()){ // サイズ未満なら.
    return array_->get(current_); // array_のcurrent_番目をgetして返す.
  }
  else{ // サイズを超える場合.
    return NULL; // NULLを返す.
  }

}

// メンバ関数next
void class_iterator::next(){

  // 現在位置を先に進める.
  if (current_ < array_->get_size()){ // array_->get_sizeまでは進める.
    current_++; // current_を増やす.
  }

}

// メンバ関数end
class_element *class_iterator::end(){

  // ここはNULLを返す.
  return NULL; // NULLを返す.

}
