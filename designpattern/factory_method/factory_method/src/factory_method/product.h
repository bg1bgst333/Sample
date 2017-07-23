// 二重インクルード防止
#ifndef __PRODUCT_H_
#define __PRODUCT_H_

// インターフェースinterface_productの定義
class interface_product{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_product(){}; // コンストラクタinterface_product
    virtual ~interface_product(){}; // デストラクタ~interface_product
    // メンバ関数
    virtual void print() = 0; // 純粋仮想関数print

};

#endif
