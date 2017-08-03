// 二重インクルード防止
#ifndef __MEMENTO_H_
#define __MEMENTO_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "state.h" // class_state

// 前方宣言
class class_state;

// クラスclass_memento
class class_memento{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    int value_; // 値value_.

    // 非公開メンバ関数
    // コンストラクタ
    class_memento(){}; // コンストラクタclass_memento
    // メンバ関数
    void set_value(int value); // メンバ関数set_value
    int get_value() const; // メンバ関数get_value

  // 公開メンバ
  public:

    // 公開メンバ関数
    // デストラクタ
    virtual ~class_memento(){}; // デストラクタ~class_memento

  // フレンドクラス
  friend class class_state; // class_stateをフレンドクラスとすることで, class_stateはここの非公開メンバにアクセスできる.

};

#endif
