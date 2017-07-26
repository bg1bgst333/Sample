// 二重インクルード防止
#ifndef __FOOTER_PART_H_
#define __FOOTER_PART_H_

// インターフェースinterface_footer_partの定義
class interface_footer_part{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_footer_part(){}; // コンストラクタinterface_footer_part
    virtual ~interface_footer_part(){}; // デストラクタ~interface_footer_part
    // メンバ関数
    virtual void print() = 0; // 純粋仮想関数print

};

#endif
