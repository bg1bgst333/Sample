// 二重インクルード防止
#ifndef __FIRST_EVENT_H_
#define __FIRST_EVENT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "handler.h" // interface_handler

// クラスclass_first_event
class class_first_event : public interface_handler{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_first_event(){}; // コンストラクタclass_first_event
    virtual ~class_first_event(){}; // デストラクタ~class_first_event
    // メンバ関数
    virtual bool proc(int id); // メンバ関数proc

};

#endif
