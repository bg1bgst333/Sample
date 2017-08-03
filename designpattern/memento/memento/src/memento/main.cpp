// ヘッダのインクルード
// 独自のヘッダ
#include "state.h" // class_state
#include "memento.h" // class_memento

// main関数
int main(){

  // ステートの生成.
  class_state *state = new class_state(); // stateを生成.

  // ステートを進捗させる.
  state->print(); // state->printで値を出力.
  state->next(); // state->nextで次へ進める.
  state->print(); // state->printで値を出力.
  state->next(); // state->nextで次へ進める.
  state->print(); // state->printで値を出力.
  state->next(); // state->nextで次へ進める.
  state->print(); // state->printで値を出力.

  // メメントの生成.
  class_memento *memento = state->create_memento(); // state->create_mementoでmementoを生成.

  // 進捗を続ける.
  state->next(); // state->nextで次へ進める.
  state->print(); // state->printで値を出力.
  state->next(); // state->nextで次へ進める.
  state->print(); // state->printで値を出力.

  // メメントの復元.
  state->set_memento(memento); // state->set_mementoでmementoを復元.

  // ステートの値を出力.
  state->print(); // state->printで値を出力.

  // メメントの破棄.
  delete memento; // deleteでmementoを破棄.

  // ステートの破棄.
  delete state; // deleteでstateを破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
