// 二重インクルード防止
#ifndef __ROUND_BRACKETS_H_
#define __ROUND_BRACKETS_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "brackets.h" // interface_brackets

// クラスclass_round_brackets
class class_round_brackets : public interface_brackets{

  // 公開メンバ
  public:

    // 公開メンバ関数
    virtual std::string create_brackets_string(std::string str); // メンバ関数create_brackets_string

};

#endif
