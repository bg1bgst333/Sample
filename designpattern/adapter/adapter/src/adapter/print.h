// 二重インクルード防止
#ifndef __PRINT_H_
#define __PRINT_H_

// インターフェースinterface_printの定義
class interface_print{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_print(){}; // コンストラクタinterface_print
    virtual ~interface_print(){}; // デストラクタinterface_print

    // メンバ関数
    virtual void print() = 0; // 純粋仮想関数print.

};

#endif
