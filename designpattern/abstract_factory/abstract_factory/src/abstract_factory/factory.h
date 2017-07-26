// 二重インクルード防止
#ifndef __FACTORY_H_
#define __FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "header_part.h" // interface_header_part
#include "footer_part.h" // interface_footer_part

// インターフェースinterface_factoryの定義
class interface_factory{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_factory(){}; // コンストラクタinterface_factory
    virtual ~interface_factory(){}; // デストラクタ~interface_factory
    // メンバ関数
    virtual interface_header_part *create_header() = 0; // 純粋仮想関数create_header
    virtual interface_footer_part *create_footer() = 0; // 純粋仮想関数create_footer

};

#endif
