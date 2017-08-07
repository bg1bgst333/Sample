// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力.
// 独自のヘッダ
#include "framed_string_factory.h" // class_framed_string_factory

// メンバの定義
// スタティックメンバ変数
class_framed_string_factory *class_framed_string_factory::instance_ = NULL; // instance_をNULLに初期化.

// デストラクタ~class_framed_string_factory
class_framed_string_factory::~class_framed_string_factory(){

  // マップの値であるclass_framed_stringオブジェクトポインタを解放.
  std::map<std::string, class_framed_string *>::iterator itor = framed_string_map_.begin(); // を先頭にセット.
  while (itor != framed_string_map_.end()){ // 末尾まで繰り返す.
    delete itor->second; // deleteでitor->secondを解放.
    itor++; // 次へ進める.
  }
  framed_string_map_.clear(); // framed_string_map_をクリア.

}

// メンバ関数get_instance
class_framed_string_factory *class_framed_string_factory::get_instance(){

  // インスタンスがなければ生成.
  if (instance_ == NULL){ // instance_がNULLなら.
    instance_ = new class_framed_string_factory(); // instance_生成.
  }
  return instance_; // instance_を返す.

}

// メンバ関数delete_instance
void class_framed_string_factory::delete_instance(){

  // インスタンスの解放.
  if (instance_ != NULL){ // instance_があれば.
    delete instance_; // instance_を解放.
    instance_ = NULL; // instance_にNULLをセット.
  }

}

// メンバ関数get_framed_string
class_framed_string* class_framed_string_factory::get_framed_string(std::string str){

  // マップに無い場合は新規作成.
  if (framed_string_map_.find(str) == framed_string_map_.end()){ // みつからない.
    framed_string_map_[str] = new class_framed_string(str); // 新規作成して追加.
    std::cout << "create " << str << " frame" << std::endl; // 先頭にcreateを付けて出力.
  }
  else{
    std::cout << "get " << str << " frame" << std::endl; // 先頭にgetを付けて出力.
  }
  return framed_string_map_[str]; // framed_string_map_を返す.

}
