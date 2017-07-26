// 二重インクルード防止
#ifndef __HEADER_PART_H_
#define __HEADER_PART_H_

// インターフェースinterface_header_partの定義
class interface_header_part{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_header_part(){}; // コンストラクタinterface_header_part
    virtual ~interface_header_part(){}; // デストラクタ~interface_header_part
    // メンバ関数
    virtual void print() = 0; // 純粋仮想関数print

};

#endif
