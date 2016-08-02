// 二重インクルードの防止
#ifndef PRIVATE_DERIVED_H
#define PRIVATE_DERIVED_H

// ヘッダのインクルード
// 独自のヘッダ
#include "private.h" // クラスclass_private

// class_privateのprotected継承クラスclass_private_derivedの定義.
class class_private_derived : protected class_private{

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void print_private(); // class_privateのメンバを出力.

};

#endif
