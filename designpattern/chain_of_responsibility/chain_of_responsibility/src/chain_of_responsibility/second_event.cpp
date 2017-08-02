// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "second_event.h" // class_second_event

// メンバの定義
// メンバ関数proc
bool class_second_event::proc(int id){

  // idで処理するかどうか判断.
  if (id == 2){ // idが2なら.
    std::cout << "second proc done!" << std::endl; // "second proc done!"と出力.
    return true; // 処理したのでtrue.
  }
  else{
    return false; // 処理しないのでfalse.
  }

}
  
