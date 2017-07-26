// ヘッダのインクルード
// 独自のヘッダ
#include "second_factory.h" // class_second_factory
#include "second_header_part.h" // class_second_header_part
#include "second_footer_part.h" // class_second_footer_part

// メンバの定義
// メンバ関数create_header
interface_header_part *class_second_factory::create_header(){

  // class_second_header_partオブジェクトを生成.
  return new class_second_header_part(); // newでclass_second_header_partを生成して, オブジェクトポインタを返す.

}

// メンバ関数create_footer
interface_footer_part *class_second_factory::create_footer(){

  // class_second_footer_partオブジェクトを生成.
  return new class_second_footer_part(); // newでclass_second_footer_partを生成して, オブジェクトポインタを返す.

}
