// 二重インクルード防止
#ifndef __PRINT_FACTORY_H_
#define __PRINT_FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "factory.h" // interface_factory

// マクロの定義
#define TYPE_ABC 1
#define TYPE_DEF 2

// クラスclass_print_factoryの定義
class class_print_factory : public interface_factory{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_print_factory(){}; // コンストラクタclass_print_factory
    virtual ~class_print_factory(){}; // デストラクタ~class_print_factory
    // メンバ関数
    virtual interface_product *create_instance(int type); // インスタンスを生成する純粋仮想関数create_instance

};

#endif
