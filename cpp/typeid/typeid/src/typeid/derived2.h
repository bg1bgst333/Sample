// 二重インクルードの防止
#ifndef DERIVED2_H
#define DERIVED2_H

// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base

// 派生クラス2 class_derived2の定義
class class_derived2 : public class_base{ // 派生クラス2

  // publicメンバ
  public: // 外部からアクセス可.

    // publicメンバ関数
    virtual void print_message(); // メッセージを出力するメンバ関数print_message.

};

#endif

   
