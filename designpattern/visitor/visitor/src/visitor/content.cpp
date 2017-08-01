// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "content.h" // class_content

// メンバの定義.
// コンストラクタclass_content
class_content::class_content(std::string name){

  // メンバのセット.
  name_ = name; // nameをname_にセット.

}

// メンバ関数get_name
std::string class_content::get_name(){

  // 名前を返す.
  return name_; // name_を返す.

}

// メンバ関数add
void class_content::add(interface_entry* entry){

  // できないことを出力.
  std::cout << "can't add!" << std::endl; // "can't add!"と出力.

}

// メンバ関数remove
void class_content::remove(){

  // 削除されたことを出力するだけ.
  std::cout << name_ << " content removed!" << std::endl; // name_に"content removed!"を付けて出力.
  name_ = ""; // name_に""をセット.

}

// メンバ関数accept
void class_content::accept(interface_visitor *visitor){

  // 受け入れたらビジターを呼ぶ.
  visitor->visit(this); // visitor->visitにthisを渡す.

}
