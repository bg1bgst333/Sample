// 二重インクルードの防止
#ifndef TEST4_H
#define TEST4_H

// ヘッダのインクルード
// 独自のヘッダ
#include "test2.h" // クラスclass_test2

// クラスclass_test4の定義
class class_test4 : public class_test2{ // class_test2の派生クラスclass_test4.

  // publicメンバ
  public:

    // publicメンバ関数
    explicit class_test4(const class_test2 &obj); // 引数付きコンストラクタ(const class_test2 &obj)(explicitを付ける.)

};

#endif
