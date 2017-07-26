// 二重インクルード防止
#ifndef __SECOND_FOOTER_PART_H_
#define __SECOND_FOOTER_PART_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "footer_part.h" // interface_footer_part

// クラスclass_second_footer_partの定義
class class_second_footer_part : public interface_footer_part{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_second_footer_part(){}; // コンストラクタclass_second_footer_part
    virtual ~class_second_footer_part(){}; // デストラクタ~class_second_footer_part
    // メンバ関数
    virtual void print(); // 出力するメンバ関数print.

};

#endif
