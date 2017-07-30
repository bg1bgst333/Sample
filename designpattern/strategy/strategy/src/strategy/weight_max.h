// 二重インクルード防止
#ifndef __WEIGHT_MAX_H_
#define __WEIGHT_MAX_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "max_strategy.h" // interface_max_strategy

// クラスclass_weight_max
class class_weight_max : public interface_max_strategy{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_weight_max(){}; // コンストラクタ
    virtual ~class_weight_max(){}; // デストラクタ
    // メンバ関数
    virtual int max(class_measurable objs[], int size); // メンバ関数max

};
    
#endif
