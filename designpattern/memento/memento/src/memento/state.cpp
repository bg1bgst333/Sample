// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "state.h" // class_state
#include "memento.h" // class_memento

// メンバの定義
// コンストラクタclass_state
class_state::class_state(){

  // メンバの初期化.
  value_ = 0; // value_を0に初期化.

}

// メンバ関数next
void class_state::next(){

  // 1増やす.
  value_++; // value_をインクリメント.

}

// メンバ関数print
void class_state::print(){

  // 値を出力.
  std::cout << "value_ = " << value_ << std::endl; // value_を出力.

}

// メンバ関数create_memento
class_memento *class_state::create_memento(){

  // メメントの生成.
  class_memento *memento = new class_memento(); // mementoを生成.

  // 値のセット.
  memento->set_value(value_); // memento->set_valueでvalue_をセット.

  // メメントを返す.
  return memento; // mementoを返す.

}

// メンバ関数set_memento
void class_state::set_memento(const class_memento *memento){

  // メメントから値を取得してセット.
  value_ = memento->get_value(); // memento->get_value()をvalue_に代入.

}
