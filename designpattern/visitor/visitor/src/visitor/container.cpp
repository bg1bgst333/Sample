// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "container.h" // class_container

// メンバの定義
// コンストラクタclass_container
class_container::class_container(std::string name){

  // メンバにセット
  name_ = name; // nameをname_にセット.
  entries_.clear(); // entriesをクリア.

}

// デストラクタ~class_container
class_container::~class_container(){

}

// メンバ関数get_name
std::string class_container::get_name(){

  // 名前を返す.
  return name_; // name_を返す.

}

// メンバ関数add
void class_container::add(interface_entry *entry){

  // リストに追加.
  entries_.push_back(entry); // entries_.push_backでentryを追加.
  // 追加されたことを出力.
  std::cout << entry->get_name() << " added!" << std::endl; // entry->get_name()に"added!"を付けて出力.

}

// メンバ関数remove
void class_container::remove(){

  // リストを全削除.
  std::list<interface_entry *>::iterator it = entries_.begin(); // イテレータitを取得.
  while(it != entries_.end()){ // 終端まで繰り返す.
    (*it)->remove(); // (*it)->removeで子の削除.
    delete *it; // *itをdeleteで破棄
    it++; // itを進める.
  }
  entries_.clear(); // entries_.clearでリストクリア.
  // 削除されたことを出力.
  std::cout << name_ << " container removed!" << std::endl; // name_に" container removed!"を付けて出力.
  name_ = ""; // name_に""をセット.

}

// メンバ関数accept
void class_container::accept(interface_visitor *visitor){

  // 受け入れたらビジターを呼ぶ.
  visitor->visit(this); // visitor->visitにthisを渡す.

}

// メンバ関数get_entries
std::list<interface_entry *> class_container::get_entries(){

  // エントリリストを返す.
  return entries_; // entries_を返す.

}
