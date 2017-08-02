// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "front.h" // class_front
#include "data_list.h" // class_data_list
#include "ng_list.h" // class_ng_list

// メンバの定義
// 静的メンバ関数search
bool class_front::search(std::string data){

  // データリスト生成.
  class_data_list *data_list = new class_data_list(); // data_list生成.
  bool result = data_list->search(data); // data_list->searchでdataを探す.
  if (!result){ // resultがFALSEなら.
    std::cout << data << " not found!" << std::endl; // "〜 not found!"と出力.
    delete data_list; // data_listを破棄.
    return false; // falseを返す.
  }
  else{ // resultがTRUEなら.
    // 見つかったが, NGリストにないかをチェックする.
    class_ng_list *ng_list = new class_ng_list(); // ng_list生成.
    bool ng = ng_list->search(data); // ng_list->searchでng_listにあるか探す.
    if (ng){ // あった.
      std::cout << data << " NG!" << std::endl; // "〜 NG!"と出力.
      delete ng_list; // ng_listを破棄.
      delete data_list; // data_listも破棄.
      return false; // falseを返す.
    }
    else{ // ない.
      std::cout << data << " OK!" << std::endl; // "〜 OK!"と出力.
      delete ng_list; // ng_listを破棄.
      delete data_list; // data_listも破棄.
      return true; // trueを返す.
    }
  }

}
