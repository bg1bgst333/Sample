// 二重インクルードの防止
#ifndef BASE_H
#define BASE_H

// 基底クラスclass_baseの定義
class class_base{ // 基底クラス

  // publicメンバ
  public: // 外部からアクセス可.

    // publicメンバ関数
    virtual void print_message(); // メッセージを出力するメンバ関数print_message.

};

#endif
