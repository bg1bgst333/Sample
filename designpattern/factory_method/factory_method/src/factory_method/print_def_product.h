// 二重インクルード防止
#ifndef __PRINT_DEF_PRODUCT_H_
#define __PRINT_DEF_PRODUCT_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "product.h" // interface_product

// クラスclass_print_def_productの定義
class class_print_def_product : public interface_product{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_def_product(){}; // コンストラクタclass_print_def_product
    virtual ~class_print_def_product(){}; // デストラクタ~class_print_def_product
    // メンバ関数
    void print(); // 出力関数print

};

#endif
