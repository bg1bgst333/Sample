// 二重インクルードの防止
#ifndef DERIVED1_H
#define DERIVED1_H

// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base

// 派生クラス1 class_derived1の定義
class class_derived1 : public class_base{ // 派生クラス1

  // publicメンバ
  public: // 外部からアクセス可.

    // publicメンバ関数
    virtual void print_message(); // メッセージを出力するメンバ関数print_message.

};

#endif

   
