// 二重インクルード防止
#ifndef __PRINT_H_
#define __PRINT_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_printの定義
class interface_print{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_print(){}; // コンストラクタ
    virtual ~interface_print(){}; // デストラクタ
    // メンバ関数
    virtual void print(std::string str) = 0; // 純粋仮想関数print

};

#endif
