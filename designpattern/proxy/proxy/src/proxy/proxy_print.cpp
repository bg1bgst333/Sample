// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "proxy_print.h" // class_print_proxy

// メンバの定義
// コンストラクタclass_proxy_print
class_proxy_print::class_proxy_print(){

  // メンバの初期化.
  simple_print_ = NULL; // simple_print_をNULLに初期化.

}

// 引数付きコンストラクタclass_proxy_print(class_simple_print *simple_print)
class_proxy_print::class_proxy_print(class_simple_print *simple_print){

  // メンバにセット.
  simple_print_ = simple_print; // simple_printをsimple_print_にセット.

}

// デストラクタ~class_proxy_print()
class_proxy_print::~class_proxy_print(){

  // メンバオブジェクトがあったら破棄.
  if (simple_print_ != NULL){
    delete simple_print_; // deleteでsimple_print_を破棄.
    simple_print_ = NULL; // simple_print_にNULLをセット.
    std::cout << "delete simple_print_" << std::endl; // "delete simple_print_"と出力.
  }

}

// 演算子オーバーロード->
class_simple_print *class_proxy_print::operator->(){

  // ポインタを返す.
  return simple_print_; // simple_print_を返す.

}

// 演算子オーバーロード*
class_simple_print &class_proxy_print::operator*(){

  // 実体の参照を返す.
  return *simple_print_; // +simple_print_を返す.

}

// メンバ関数print
void class_proxy_print::print(std::string str){

  // メンバオブジェクトがなかったら生成.
  if (simple_print_ == NULL){
    simple_print_ = new class_simple_print(); // simple_print_の生成.
  }
  // 出力.
  simple_print_->print(str); // simple_print_->printでstrを出力.

}
