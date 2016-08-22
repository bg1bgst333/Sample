// 二重インクルードの防止
#ifndef DERIVED2_H
#define DERIVED2_H

// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseの派生クラス2 class_derived2の定義
class class_derived2 : public class_base{

  // publicメンバ
  public:

    // publicメンバ関数
    virtual void derived2_func(); // derived2関数(virtualをもっていないとダウンキャストできない.)

};

#endif
