// 二重インクルード防止
#ifndef __FRAMED_STRING_H_
#define __FRAMED_STRING_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// クラスclass_framed_string
class class_framed_string{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string str_; // std::string型str_.

  // 公開メンバ関数
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_framed_string(std::string str); // 引数付きコンストラクタ
    virtual ~class_framed_string(){}; // デストラクタ
    // メンバ関数
    void print(); // メンバ関数print

};

#endif  
