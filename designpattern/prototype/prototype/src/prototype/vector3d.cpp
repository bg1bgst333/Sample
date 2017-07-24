// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "vector3d.h" // class_vector3d

// メンバの定義
// コンストラクタclass_vector3d
class_vector3d::class_vector3d(){

  // メンバの初期化.
  for (int i = 0; i < 3; i++){ // 3回繰り返す.
    e_[i] = 0; // 0に初期化.
  }

}

// コピーコンストラクタclass_vector3d
class_vector3d::class_vector3d(const class_vector3d &obj){

  // メンバのコピー.
  for (int i = 0; i < 3; i++){ // 3回繰り返す.
    e_[i] = obj.e_[i]; // obj.e_[i]をe_[i]にコピー.
  }

}

// デストラクタ~class_vector3d
class_vector3d::~class_vector3d(){

  // メンバの初期化.
  for (int i = 0; i < 3; i++){ // 3回繰り返す.
    e_[i] = 0; // 0に初期化.
  }

}

// メンバ関数clone
interface_cloneable *class_vector3d::clone(){

  // クローンを生成.
  interface_cloneable *clone_obj = new class_vector3d(*this); // 自身のコピーコンストラクタでクローンを生成し, clone_objに格納.

  // clone_objを返す.
  return clone_obj; // clone_objを返す.

}

// メンバ関数print
void class_vector3d::print(){

  // (e_[0], e_[1], e_[2])形式で出力.
  std::cout << "(" << e_[0] << ", " << e_[1] << ", " << e_[2] << ")" << std::endl; // 出力演算子で各成分を出力.

}

// メンバ関数set_e
void class_vector3d::set_e(int e[]){

  // 各メンバにセット.
  for (int i = 0; i < 3; i++){ // 3回繰り返す.
    e_[i] = e[i]; // e_[i]にe[i]をセット.
  }

}
