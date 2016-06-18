// 二重インクルードの防止
#ifndef PROTECTED_H
#define PROTECTED_H

// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseのprotected継承クラスclass_protectedの定義
class class_protected : protected class_base{ //protected継承クラス

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void print_base(); // class_baseのメンバを出力.

};

#endif

