// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "brackets_factory.h" // class_brackets_factory

// コンストラクタclass_brackets_factory
class_brackets_factory::class_brackets_factory(interface_brackets *brackets){

  // メンバにセット.
  brackets_ = brackets; // brackets_にbracketsをセット.

}

// デストラクタ~class_brackets_factory
class_brackets_factory::~class_brackets_factory(){

  // メンバを解放.
  if (brackets_ != NULL){ // brackets_がNULLでないなら.
    delete brackets_; // deleteでbrackets_を解放.
    brackets_ = NULL; // NULLをセット.
    std::cout << "delete brackets_" << std::endl; // "delete brackets_"と出力.
  }

}

// メンバ関数create
std::string class_brackets_factory::create(std::string str){

  // 括弧付き文字列を返す.
  if (brackets_ != NULL){ // brackets_がNULLでないなら.
    return brackets_->create_brackets_string(str); // brackets_->create_brackets_stringにstrを渡した結果を返す.
  }
  else{ // それ以外.
    return ""; // ""を返す.
  }

}
