// 二重インクルード防止
#ifndef __PRINT_TEXT_H_
#define __PRINT_TEXT_H_

// ヘッダのインクルード
// 既存のヘッダ
#include <string> // std::string

// インターフェースinterface_print_text
class interface_print_text{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_print_text(){}; // コンストラクタ
    virtual ~interface_print_text(){}; // デストラクタ
    // メンバ関数
    virtual void print_text(std::string text) = 0; // 純粋仮想関数print_text

}; 

#endif
