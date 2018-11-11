// 二重インクルード防止
#ifndef __BRACKETS_H_
#define __BRACKETS_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_brackets
class interface_brackets{

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual std::string create_brackets_string(std::string str) = 0; // 純粋仮想関数create_brackets_string

};

#endif
