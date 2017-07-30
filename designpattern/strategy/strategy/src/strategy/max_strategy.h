// 二重インクルード防止
#ifndef __MAX_STRATEGY_H_
#define __MAX_STRATEGY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "measurable.h" // class_measurable

// インターフェースinterface_max_strategy
class interface_max_strategy{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_max_strategy(){}; // コンストラクタ
    virtual ~interface_max_strategy(){}; // デストラクタ
    // メンバ関数
    virtual int max(class_measurable objs[], int size) = 0; // 純粋仮想関数max

};

#endif
