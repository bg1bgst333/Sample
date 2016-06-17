// 二重インクルードの防止
#ifndef PUBLIC_H
#define PUBLIC_H

// ヘッダのインクルード
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseのpublic継承クラスclass_publicの定義
class class_public : public class_base{ // public継承クラス

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ関数
    void print_base(); // class_baseのメンバを出力.

};

#endif
