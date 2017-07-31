// 二重インクルード防止
#ifndef __PRINT_H_
#define __PRINT_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_print
class interface_print{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_print(){}; // コンストラクタinterface_print
    virtual ~interface_print(){}; // デストラクタ~interface_print
    // メンバ関数
    virtual std::string get_text() = 0; // 純粋仮想関数get_text.

};

#endif
