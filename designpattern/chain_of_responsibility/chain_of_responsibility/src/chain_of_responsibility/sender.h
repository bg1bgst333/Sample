// 二重インクルード防止
#ifndef __SENDER_H_
#define __SENDER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list
// 独自のヘッダ
#include "handler.h" // interface_handler

// クラスclass_sender
class class_sender{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<interface_handler *> handler_list_; // ハンドラリストhandler_list_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_sender(){}; // コンストラクタclass_sender
    virtual ~class_sender(); // デストラクタclass_sender
    void add(interface_handler *handler); // メンバ関数add
    void send(int id); // メンバ関数send

};

#endif
