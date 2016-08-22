// 二重インクルードの防止
#ifndef DERIVED1_H
#define DERIVED1_H

// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base

// class_baseの派生クラス1 class_derived1の定義
class class_derived1 : public class_base{

  // publicメンバ
  public:

    // publicメンバ関数
    virtual void derived1_func(); // derived1関数(virtualをもっていないとダウンキャストできない.)

};

#endif
