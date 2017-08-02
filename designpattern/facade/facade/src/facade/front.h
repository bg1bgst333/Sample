// 二重インクルード防止
#ifndef __FRONT_H_
#define __FORNT_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// クラスclass_front
class class_front{

  // 公開メンバ
  public:

    // 公開メンバ関数
    static bool search(std::string data); // メンバ関数search

};

#endif
