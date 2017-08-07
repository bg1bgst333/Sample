// ヘッダのインクルード
// 独自のヘッダ
#include "simple_print_factory.h" // class_simple_print_factory

// メンバの定義
// スタティックメンバ変数
class_simple_print_factory *class_simple_print_factory::instance_ = NULL; // instance_をNULLに初期化.

// デストラクタ~class_simple_print_factory
class_simple_print_factory::~class_simple_print_factory(){

}

// メンバ関数get_instance
class_simple_print_factory *class_simple_print_factory::get_instance(){

  // インスタンスがなければ生成.
  if (instance_ == NULL){ // instance_がNULL
    instance_ = new class_simple_print_factory(); // instance_生成.
  }
  return instance_; // instance_を返す.

}

// メンバ関数delete_instance
void class_simple_print_factory::delete_instance(){

  // インスタンスの解放.
  if (instance_ != NULL){ // instance_があれば.
    delete instance_; // instance_を解放.
    instance_ = NULL; // instance_にNULLをセット.
  }

}

// メンバ関数create_simple_print
class_simple_print *class_simple_print_factory::create_simple_print(){

  // class_simple_printオブジェクトの生成.
  return new class_simple_print(); // newでclass_simple_printオブジェクトを作成し, 返す.

}
