// 二重インクルード防止
#ifndef __FIRST_FACTORY_H_
#define __FIRST_FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "factory.h" // interface_factory
#include "header_part.h" // interface_header_part
#include "footer_part.h" // interface_footer_part

// クラスclass_first_factory
class class_first_factory : public interface_factory{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとでトラクタ
    class_first_factory(){}; // コンストラクタclass_first_factory
    virtual ~class_first_factory(){}; // デストラクタ~class_first_factory
    // メンバ関数
    virtual interface_header_part *create_header(); // ヘッダ作成create_header
    virtual interface_footer_part *create_footer(); // フッタ作成create_footer

};

#endif
