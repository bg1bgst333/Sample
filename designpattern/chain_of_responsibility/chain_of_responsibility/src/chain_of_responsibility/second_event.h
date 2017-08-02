// 二重インクルード防止
#ifndef __SECOND_EVENT_H_
#define __SECOND_EVENT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "handler.h" // interface_handler

// クラスclass_second_event
class class_second_event : public interface_handler{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_second_event(){}; // コンストラクタclass_second_event
    virtual ~class_second_event(){}; // デストラクタ~class_second_event
    // メンバ関数
    virtual bool proc(int id); // メンバ関数proc

};

#endif
