// 二重インクルード防止
#ifndef __FIRST_HEADER_PART_H_
#define __FIRST_HEADER_PART_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "header_part.h" // interface_header_part

// クラスclass_first_header_partの定義
class class_first_header_part : public interface_header_part{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_first_header_part(){}; // コンストラクタclass_first_header_part
    virtual ~class_first_header_part(){}; // デストラクタ~class_first_header_part
    // メンバ関数
    virtual void print(); // 出力するメンバ関数print.

};

#endif
