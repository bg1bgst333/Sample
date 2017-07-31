// 二重インクルード防止
#ifndef __CONTAINER_H_
#define __CONTAINER_H_

// ヘッダのインクルード
// 既定のヘッダ
#include <list> // std::list

// 独自のヘッダ
#include "entry.h" // interface_entry

// クラスclass_container
class class_container : public interface_entry{

  // 非公開メンバ
  private:

    // 非公開メンバ変数
    std::string name_; // 名前name_.
    std::list<interface_entry *> entries_; // エントリリストentries_.    

  // 公開メンバ
  public:

    // 公開メンバ関数
    // コンストラクタとデストラクタ
    class_container(std::string name); // 引数付きコンストラクタclass_container
    virtual ~class_container(); // デストラクタ~class_container
    // メンバ関数
    virtual std::string get_name(); // メンバ関数get_name
    virtual void add(interface_entry *entry); // メンバ関数add
    virtual void remove(); // メンバ関数remove

};

#endif
