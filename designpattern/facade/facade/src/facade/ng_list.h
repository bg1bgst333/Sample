// 二重インクルード防止
#ifndef __NG_LIST_H_
#define __NG_LIST_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <string> // std::string
#include <list> // std::list

// クラスclass_ng_list
class class_ng_list{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::list<std::string> list_; // データリストlist_

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_ng_list(); // コンストラクタclass_ng_list
    virtual ~class_ng_list(); // デストラクタ~class_ng_list
    // メンバ関数
    bool search(std::string data); // メンバ関数search

};

#endif
