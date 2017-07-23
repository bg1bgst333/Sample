// ヘッダのインクルード
// 既定のヘッダ
#include <cstddef> // C++定義
// 独自のヘッダ
#include "print_factory.h" // class_print_factory
#include "print_abc_product.h" // class_print_abc_product.h
#include "print_def_product.h" // class_print_def_product.h

// メンバの定義
// メンバ関数create_instance
interface_product *class_print_factory::create_instance(int type){

  // typeによって振り分ける.
  if (type == TYPE_ABC){ // TYPE_ABCなら.
    return new class_print_abc_product(); // class_print_abc_productオブジェクトを生成し, ポインタを返す.
  }
  else if (type == TYPE_DEF){ // TYPE_DEFなら.
    return new class_print_def_product(); // class_print_def_productオブジェクトを生成し, ポインタを返す.
  }
  else{ // それ以外.
    return NULL; // NULLを返す.
  }

}
