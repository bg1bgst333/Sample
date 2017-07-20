// ヘッダのインクルード
// 独自のヘッダ
#include "element.h" // class_element

// メンバの定義
// コンストラクタ
class_element::class_element(){

}

// 引数付きコンストラクタ
class_element::class_element(std::string name, int num){

  // 引数をメンバにセット.
  name_ = name; // nameをname_にセット.
  num_ = num; // numをnum_にセット.

}

// メンバ関数set_name
void class_element::set_name(std::string name){

  // 引数をメンバにセット.
  name_ = name; // nameをname_にセット.

}

// メンバ関数get_name
std::string class_element::get_name(){

  // メンバを返す.
  return name_; // name_を返す.

}

// メンバ関数set_num
void class_element::set_num(int num){

  // 引数をメンバにセット.
  num_ = num; // numをnum_にセット.

}

// メンバ関数get_name
int class_element::get_num(){

  // メンバを返す.
  return num_; // num_を返す.

}
