// 二重インクルード防止
#ifndef __BRACKETS_FACTORY_H_
#define __BRACKETS_FACTORY_H_

// ヘッダのインクルード
// 独自のヘッダ
#include "brackets.h" // interface_brackets

// クラスclass_brackets_factory
class class_brackets_factory{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    interface_brackets *brackets_ = NULL; // ブラケットオブジェクトポインタbrackets_をNULLで初期化.

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ.
    class_brackets_factory(interface_brackets *brackets); // コンストラクタcreate_brackets_factory
    virtual ~class_brackets_factory(); // デストラクタ~create_brackets_factory
    // メンバ関数
    std::string create(std::string str); // メンバ関数create

};

#endif
