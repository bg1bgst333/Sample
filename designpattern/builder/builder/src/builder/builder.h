// 二重インクルード防止
#ifndef __BUILDER_H_
#define __BUILDER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string

// インターフェースinterface_builder
class interface_builder{

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    interface_builder(){}; // コンストラクタinterface_builder
    virtual ~interface_builder(){}; // デストラクタ~interface_builder
    // メンバ関数
    virtual void set_title(std::string title) = 0; // 純粋仮想関数set_title
    virtual void set_content(std::string content) = 0; // 純粋仮想関数set_content
    virtual std::string build() = 0; // 純粋仮想関数build

};

#endif
