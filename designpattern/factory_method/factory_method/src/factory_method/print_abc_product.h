// 二重インクルード防止
#ifndef __PRINT_ABC_PRODUCT_H_
#define __PRINT_ABC_PRODUCT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "product.h" // interface_product

// クラスclass_print_abc_productの定義
class class_print_abc_product : public interface_product{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_abc_product(){}; // コンストラクタclass_print_abc_product
    virtual ~class_print_abc_product(){}; // デストラクタ~class_print_abc
    // メンバ関数
    void print(); // 出力関数print

};

#endif
