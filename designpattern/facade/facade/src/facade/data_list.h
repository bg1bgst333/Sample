// 二重インクルード防止
#ifndef __DATA_LIST_H_
#define __DATA_LIST_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
#include <list> // std::list

// クラスclass_data_list
class class_data_list{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<std::string> list_; // データリストlist_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_data_list(); // コンストラクタclass_data_list
    virtual ~class_data_list(); // デストラクタ~class_data_list
    // メンバ関数
    bool search(std::string data); // メンバ関数search

};

#endif
