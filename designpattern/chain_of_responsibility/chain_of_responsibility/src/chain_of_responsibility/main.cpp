// ヘッダのインクルード
// 独自のヘッダ
#include "first_event.h" // class_first_event
#include "second_event.h" // class_second_event
#include "sender.h" // class_sender

// main関数
int main(){

  // ハンドラの作成.
  interface_handler *first = new class_first_event(); // class_first_eventオブジェクトポインタをfirstに格納.
  interface_handler *second = new class_second_event(); // class_second_eventオブジェクトポインタをsecondに格納.

  // センダーの作成.
  class_sender *sender = new class_sender(); // class_senderオブジェクトポインタをsenderに格納.

  // センダーにハンドラを追加.
  sender->add(first); // sender->addでfirstを追加.
  sender->add(second); // sender->addでsecondを追加.

  // イベント送信.
  sender->send(1); // イベントIDとして1を送信.
  sender->send(2); // イベントIDとして2を送信.
  sender->send(3); // イベントIDとして3を送信.

  // センダーの破棄.
  delete sender; // deleteでsenderを破棄.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
