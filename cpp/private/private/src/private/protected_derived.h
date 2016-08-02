// 二重インクルードの防止
#ifndef PROTECTED_DERIVED_H
#define PROTECTED_DERIVED_H

// ヘッダのインクルード
// 独自のヘッダ
#include "protected.h" // クラスclass_protected

// class_protectedのprotected継承クラスclass_protected_derivedの定義.
class class_protected_derived : protected class_protected{

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void print_protected(); // class_protectedのメンバを出力.

};

#endif
