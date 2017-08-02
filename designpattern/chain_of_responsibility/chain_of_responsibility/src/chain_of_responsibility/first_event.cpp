// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "first_event.h" // class_first_event

// メンバの定義
// メンバ関数proc
bool class_first_event::proc(int id){

  // idで処理するかどうか判断.
  if (id == 1){ // idが1なら.
    std::cout << "first proc done!" << std::endl; // "first proc done!"と出力.
    return true; // 処理したのでtrue.
  }
  else{
    return false; // 処理しないのでfalse.
  }

}
  
