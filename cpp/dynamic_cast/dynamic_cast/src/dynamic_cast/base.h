// 二重インクルードの防止
#ifndef BASE_H
#define BASE_H

// ヘッダのインクルード
#include <iostream> // C++標準入出力

// 基底クラスclass_baseの定義
class class_base{

  // pulicメンバ
  public:

    // publicメンバ関数
    virtual void base_func(); // base関数(virtualをもっていないとダウンキャストできない.)

};

#endif
