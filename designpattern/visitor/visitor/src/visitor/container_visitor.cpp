// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <string> // std::string
// 独自のヘッダ
#include "container_visitor.h" // class_container_visitor

// メンバの定義
// メンバ関数visitor(class_content *content)
void class_container_visitor::visit(class_content *content){

  // contentの名前を出力.
  std::cout << "container_visitor(content): " << content->get_name() << std::endl; // content->get_nameで名前を出力.

}

// メンバ関数visitor(class_container *container){
void class_container_visitor::visit(class_container *container){

  // containerの名前を出力.
  std::cout << "container_visitor(container): " << container->get_name() << std::endl; // container->get_nameで名前を出力.

  // エントリリスト取得.
  std::list<interface_entry *> entries = container->get_entries(); // container->get_entriesでエントリリスト取得.
  std::list<interface_entry *>::iterator itor = entries.begin(); // itorをentries.begin()で初期化.
  while(itor != entries.end()){ // itorがend()に来るまで繰り返す.
    (*itor)->accept(this); // (*itor)->acceptにthisを渡す.
    itor++; // 増やす.
  }

}
