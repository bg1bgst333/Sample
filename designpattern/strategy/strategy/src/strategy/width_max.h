// 二重インクルード防止
#ifndef __WIDTH_MAX_H_
#define __WIDTH_MAX_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "max_strategy.h" // interface_max_strategy

// クラスclass_width_max
class class_width_max : public interface_max_strategy{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_width_max(){}; // コンストラクタ
    virtual ~class_width_max(){}; // デストラクタ
    // メンバ関数
    virtual int max(class_measurable objs[], int size); // メンバ関数max

};
    
#endif
