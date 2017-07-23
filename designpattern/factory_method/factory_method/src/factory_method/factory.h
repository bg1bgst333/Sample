// 二重インクルード防止
#ifndef __FACTORY_H_
#define __FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "product.h" // interface_product

// インターフェースinterface_factoryの定義
class interface_factory{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_factory(){}; // コンストラクタinterface_factory
    virtual ~interface_factory(){}; // デストラクタ~interface_factory
    // メンバ関数
    virtual interface_product *create_instance(int type) = 0; // インスタンスを生成する純粋仮想関数create_instance

};
    
#endif
