// 二重インクルードの防止
#ifndef BASE_H
#define BASE_H

// ヘッダのインクルード
#include <iostream> // C++標準入出力

// 基底クラスclass_baseの定義
class class_base{ // 基底クラス

  // privateメンバ
  private: // このクラス内部からのみアクセス可.

    // privateメンバ変数
    int private_variable_; // private変数

    // privateメンバ関数
    void private_function(); // private関数

  // protectedメンバ
  protected: // 派生クラスからアクセス可.

    // protectedメンバ変数
    int protected_variable_; // protected変数

    // protectedメンバ関数
    void protected_function(); // protected関数

  // publicメンバ
  public: // このクラスの外部からもアクセス可.

    // publicメンバ変数
    int public_variable_; // public変数

    // publicメンバ関数
    void public_function(); // public関数

};

#endif
