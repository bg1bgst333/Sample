// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "sender.h" // class_sender

// メンバの定義
// デストラクタ~class_sender
class_sender::~class_sender(){

  // イベントリストの破棄.
  std::list<interface_handler *>::iterator itor = handler_list_.begin(); // itorにhandler_list_.beginで先頭をセット.
  while (itor != handler_list_.end()){ // 末尾まで繰り返す.
    delete *itor; // deleteで*itorの指すハンドラオブジェクトポインタを破棄.
    itor++; // itorを進める.
  }
  handler_list_.clear(); // handler_list_.clearでクリア.

}

// メンバ関数add
void class_sender::add(interface_handler *handler){

  // リストに登録.
  handler_list_.push_back(handler); // handler_list_.push_backでhandlerを登録.

}

// メンバ関数send
void class_sender::send(int id){

  // イベントの実行判断.
  std::list<interface_handler *>::iterator itor = handler_list_.begin(); // itorにhandler_list_.beginで先頭をセット.
  while (itor != handler_list_.end()){ // 末尾まで繰り返す.
    if ((*itor)->proc(id)){ // procがTRUEなら実行された.
      std::cout << "class_sender::send TRUE!" << std::endl; // "class_sender::send TRUE!"と出力.
      return;
    }
    itor++; // itorを進める.
  }

  // どれも実行されない場合.
  std::cout << "class_sender::send ALL FALSE!" << std::endl; // "class_sender::send ALL FALSE!"と出力.

}
