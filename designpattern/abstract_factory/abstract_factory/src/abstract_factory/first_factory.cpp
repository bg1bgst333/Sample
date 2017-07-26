// ヘッダのインクルード
// 独自のヘッダ
#include "first_factory.h" // class_first_factory
#include "first_header_part.h" // class_first_header_part
#include "first_footer_part.h" // class_first_footer_part

// メンバの定義
// メンバ関数create_header
interface_header_part *class_first_factory::create_header(){

  // class_first_header_partオブジェクトを生成.
  return new class_first_header_part(); // newでclass_first_header_partを生成して, オブジェクトポインタを返す.

}

// メンバ関数create_footer
interface_footer_part *class_first_factory::create_footer(){

  // class_first_footer_partオブジェクトを生成.
  return new class_first_footer_part(); // newでclass_first_footer_partを生成して, オブジェクトポインタを返す.

}
