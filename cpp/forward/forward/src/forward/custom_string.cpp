// ヘッダのインクルード
// 既定のヘッダ
#include <cstring> // C文字列処理
// 独自のヘッダ
#include "custom_string.h" // class_custom_string

// コンストラクタ
class_custom_string::class_custom_string(){

  // メンバの初期化.
  str_ = nullptr; // str_にnullptrをセット.
  len_ = 0; // len_に0をセット.

}

// 引数付きコンストラクタ
class_custom_string::class_custom_string(const char *str){

  // strの長さを取得.
  len_ = strlen(str); // strlenでstrの長さを取得し, len_に格納.

  // 動的配列の作成.
  str_ = new char[len_ + 1]; // len_ + 1の長さのchar型動的配列をnewで確保し, ポインタをstr_に格納.

  // 文字列のコピー.
  strcpy(str_, str); // strcpyでstrをstr_にコピー.

}

// コピーコンストラクタ
class_custom_string::class_custom_string(const class_custom_string &obj){

  // objの長さを取得.
  len_ = obj.len_; // obj.len_をlen_に格納.

  // 動的配列の作成.
  str_ = new char[len_ + 1]; // len_ + 1の長さのchar型動的配列をnewで確保し, ポインタをstr_に格納.

  // 文字列のコピー.
  strcpy(str_, obj.str_); // strcpyでobj.str_をstr_にコピー.

}

// ムーブコンストラクタ
class_custom_string::class_custom_string(class_custom_string &&obj){

  // len_を移す.
  len_ = obj.len_; // obj.len_をlen_に格納.
  obj.len_ = 0; // obj.len_は0にセット.

  // str_を移す.
  str_ = obj.str_; // obj.str_をstr_に格納.
  obj.str_ = nullptr; // nullptrをobj.str_にセット.

}

// デストラクタ
class_custom_string::~class_custom_string(){

  // str_があったら破棄.
  if (str_ != nullptr){ // str_がnullptrでなければ.
    delete [] str_; // delete [] でstr_を破棄.
    str_ = nullptr; // str_にnullptrをセット.
  }
  len_ = 0; // len_に0をセット.

}

// コピー代入演算子
class_custom_string &class_custom_string::operator=(const class_custom_string &obj){

  // objの長さを取得.
  len_ = obj.len_; // obj.len_をlen_に格納.

  // 配列があれば破棄.
  if (str_ != nullptr){ // str_がnullptrでなければ.
    delete [] str_; // delete [] でstr_を破棄.
  }

  // 動的配列の作成.
  str_ = new char[len_ + 1]; // len_ + 1の長さのchar型動的配列をnewで確保し, ポインタをstr_に格納.

  // 文字列のコピー.
  strcpy(str_, obj.str_); // strcpyでobj.str_をstr_にコピー.

  // 自身の参照を返す.
  return *this; // *thisを返す.

}

// ムーブ代入演算子
class_custom_string &class_custom_string::operator=(class_custom_string &&obj){

  // len_を移す.
  len_ = obj.len_; // obj.len_をlen_に格納.
  obj.len_ = 0; // obj.len_は0にセット.

  // 配列があれば破棄.
  if (str_ != nullptr){ // str_がnullptrでなければ.
    delete [] str_; // delete [] でstr_を破棄.
  }

  // str_を移す.
  str_ = obj.str_; // obj.str_をstr_に格納.
  obj.str_ = nullptr; // nullptrをobj.str_にセット.

  // 自身の参照を返す.
  return *this; // *thisを返す.

}

// メンバ関数set_custom_string
void class_custom_string::set_custom_string(const char *str){

  // strの長さを取得.
  len_ = strlen(str); // strlenでstrの長さを取得し, len_に格納.

  // 配列があれば破棄.
  if (str_ != nullptr){ // str_がnullptrでなければ.
    delete [] str_; // delete [] でstr_を破棄.
  }

  // 動的配列の作成.
  str_ = new char[len_ + 1]; // len_ + 1の長さのchar型動的配列をnewで確保し, ポインタをstr_に格納.

  // 文字列のコピー.
  strcpy(str_, str); // strcpyでstrをstr_にコピー.

}

// メンバ関数get_custom_string
const char *class_custom_string::get_custom_string(){

  // 文字列を返す.
  return str_; // str_を返す.

}
