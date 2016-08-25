// 二重インクルードの防止
#ifndef TEST3_H
#define TEST3_H

// ヘッダのインクルード
// 独自のヘッダ
#include "test1.h" // クラスclass_test1

// クラスclass_test3の定義
class class_test3 : public class_test1{ // class_test1の派生クラスclass_test3.

  // publicメンバ
  public:

    // publicメンバ関数
    class_test3(const class_test1 &obj); // 引数付きコンストラクタ(const class_test1 &obj)

};

#endif
