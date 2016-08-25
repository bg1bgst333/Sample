// 二重インクルードの防止
#ifndef TEST2_H
#define TEST2_H

// ヘッダのインクルード
// 独自のヘッダ
#include "test1.h" // クラスclass_test1

// クラスclass_test2の定義
class class_test2 : public class_test1{ // class_test1の派生クラスclass_test2.

  // publicメンバ
  public:

    // publicメンバ関数
    class_test2(); // コンストラクタ
    explicit class_test2(int i); // 引数付きコンストラクタ(int i)(explicitを付ける.)

};

#endif
