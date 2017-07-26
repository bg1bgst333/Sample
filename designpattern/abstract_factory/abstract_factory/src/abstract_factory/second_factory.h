// 二重インクルード防止
#ifndef __SECOND_FACTORY_H_
#define __SECOND_FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "factory.h" // interface_factory
#include "header_part.h" // interface_header_part
#include "footer_part.h" // interface_footer_part

// クラスclass_second_factory
class class_second_factory : public interface_factory{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとでトラクタ
    class_second_factory(){}; // コンストラクタclass_second_factory
    virtual ~class_second_factory(){}; // デストラクタ~class_second_factory
    // メンバ関数
    virtual interface_header_part *create_header(); // ヘッダ作成create_header
    virtual interface_footer_part *create_footer(); // フッタ作成create_footer

};

#endif
