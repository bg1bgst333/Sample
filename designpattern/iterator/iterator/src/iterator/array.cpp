// ヘッダのインクルード
// 独自のヘッダ
#include "array.h" // class_array

// メンバの定義
// コンストラクタ
class_array::class_array(int size){

  // 引数をメンバにセット.
  size_ = size; // sizeをsize_にセット.

  // 動的配列の作成.
  elements_ = new class_element[size_]; // newでclass_element動的配列を作成.(要素数size_)

}

// デストラクタ
class_array::~class_array(){

  // 動的配列の削除
  delete [] elements_; // delete []でelements_を削除.

}

// メンバ関数get
class_element *class_array::get(int index){

  // index番目の要素を返す.
  return &elements_[index]; // elements_のindex番目のアドレスを返す.

}

// メンバ関数get_size
int class_array::get_size(){

  // size_を返す.
  return size_; // size_を返す.

}
