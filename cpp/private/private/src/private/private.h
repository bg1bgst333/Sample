// 二重インクルードの防止
#ifndef PRIVATE_H
#define PRIVATE_H

// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseのprivate継承クラスclass_privateの定義
class class_private : private class_base{ // private継承クラス

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void print_base(); // class_baseのメンバを出力.

};

#endif
