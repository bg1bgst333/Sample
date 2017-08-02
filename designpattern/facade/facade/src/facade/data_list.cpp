// ヘッダのインクルード
// 独自のヘッダ
#include "data_list.h" // class_data_list

// メンバの定義
// コンストラクタclass_data_list
class_data_list::class_data_list(){

  // データの追加.
  list_.push_back("data1"); // data1を追加.
  list_.push_back("data2"); // data2を追加.
  list_.push_back("data3"); // data3を追加.

}

// デストラクタclass_data_list
class_data_list::~class_data_list(){

  // データのクリア.
  list_.clear(); // list_.clearでクリア.

}

// メンバ関数search
bool class_data_list::search(std::string data){

  // リストから探す.
  std::list<std::string>::iterator itor = list_.begin(); // 先頭をitorにセット.
  while (itor != list_.end()){ // 末尾まで繰り返す.
    if (*itor == data){ // *itorとdataが等しい場合.
      return true; // trueを返す.
    }
    itor++; // itorを進める.
  }

  // 無かった場合.
  return false; // falseを返す.

}
