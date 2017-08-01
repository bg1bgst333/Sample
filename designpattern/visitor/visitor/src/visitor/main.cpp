// ヘッダのインクルード
// 独自のヘッダ
#include "container_visitor.h" // class_container_visitor

// main関数
int main(){

  // コンテントの作成.
  interface_entry* subcontent = new class_content("<subcontent>"); // "<subcontent>"コンテントの作成.
  interface_entry* subsubcontent = new class_content("<subsubcontent>"); // "<subsubcontent>"コンテントの作成.
  // コンテナの作成.
  interface_entry* container = new class_container("<container>"); // "<container>"コンテナの作成.
  interface_entry* subcontainer = new class_container("<subcontainer>"); // "<subcontainer>"コンテナの作成.
  interface_entry* subsubcontainer = new class_container("<subsubcontainer>"); // "<subsubcontainer>"コンテナの作成.

  // コンテナにコンテントやコンテナを追加.
  subcontainer->add(subsubcontent); // subcontainerにsubsubcontentを追加.
  subcontainer->add(subsubcontainer); // subcontainerにsubsubcontainerを追加.
  container->add(subcontent); // containerにsubcontentを追加.
  container->add(subcontainer); // containerにsubcontainerを追加.

  // ビジターで走査.
  interface_visitor *visitor = new class_container_visitor(); // visitorの生成.
  container->accept(visitor); // container->acceptにvisitorを渡す.
  delete visitor; // visitorの破棄.

  // コンテナの削除.
  container->remove(); // containerの内容を削除.
  delete container; //コンテナ自信を削除.

  // プログラムの削除.
  return 0; // 0を返して正常終了.

}
