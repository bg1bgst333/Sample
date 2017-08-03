// 二重インクルード防止
#ifndef __STATE_H_
#define __STATE_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "memento.h"

// 前方宣言
class class_memento;

// クラスclass_state
class class_state{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    int value_; // 値value_.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_state(); // コンストラクタclass_state
    virtual ~class_state(){}; // デストラクタclass_state
    // メンバ関数
    void next(); // メンバ関数next
    void print(); // メンバ関数print
    class_memento *create_memento(); // メンバ関数create_memento
    void set_memento(const class_memento *memento); // メンバ関数set_memento

};

#endif
