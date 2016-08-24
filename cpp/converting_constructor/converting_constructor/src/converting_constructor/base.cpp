// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++ 標準入出力
#include <cstring> // C文字列処理
//独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseのメンバの定義
// コンストラクタclass_base(int i)
class_base::class_base(int i){

  // メンバi_の初期化
  i_ = i; // i_にiの値をセット.
  ptr_ = NULL; // ptr_をNULLにセット.

}

// コンストラクタclass_base(const char *ptr)
class_base::class_base(const char *ptr){

  // メンバptr_の初期化
  i_ = 0;
  int len = strlen(ptr); // strlenでptrの文字列長を取得し, lenに格納.
  ptr_ = new char[len + 1]; // newで長さlen + 1のchar型動的配列を確保し, ptr_に格納.
  strcpy(ptr_, ptr); // strcpyでptr_にptrをコピー.

}

// デストラクタ~class_base
class_base::~class_base(){

  // メンバの終了処理
  if (ptr_ != NULL){ // ptr_がNULLでなければ.
    delete [] ptr_; // ptr_のメモリを解放.
  }
  i_ = 0; // i_に0をセット.

}

// メンバ関数show
void class_base::show(){

  // メンバの出力
  if (ptr_ != NULL){ // ptr_がNULLでなければ.
    std::cout << "ptr_ = " << ptr_ << std::endl; // ptr_を出力.
  }
  std::cout << "i_ = " << i_ << std::endl; // i_を出力.

}
