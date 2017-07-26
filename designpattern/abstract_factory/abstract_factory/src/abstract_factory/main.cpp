// ヘッダのインクルード
// 独自のヘッダ
#include "first_factory.h" // class_first_factory
#include "second_factory.h" // class_second_factory

// main関数
int main(){

  // ファクトリーの生成.
  interface_factory *first = new class_first_factory(); // class_first_factoryオブジェクトポインタをfirstに格納.
  interface_factory *second = new class_second_factory(); // class_second_factoryオブジェクトポインタをsecoundに格納.

  // first_header, first_footerを生成.
  interface_header_part *first_header = first->create_header(); // first->create_headerでヘッダを生成.
  interface_footer_part *first_footer = first->create_footer(); // first->create_footerでフッタを生成.

  // first_header, first_footerの出力.
  first_header->print(); // first_header->printで出力.
  first_footer->print(); // first_footer->printで出力.

  // first_header, first_footerの削除.
  delete first_header; // deleteでfirst_headerを削除.
  delete first_footer; // deleteでfirst_footerを削除.

  // second_header, second_footerを生成.
  interface_header_part *second_header = second->create_header(); // second->create_headerでヘッダを生成.
  interface_footer_part *second_footer = second->create_footer(); // second->create_footerでフッタを生成.

  // second_header, second_footerの出力.
  second_header->print(); // second_header->printで出力.
  second_footer->print(); // second_footer->printで出力.

  // second_header, second_footerを生成.
  delete second_header; // deleteでsecond_headerを削除.
  delete second_footer; // deleteでsecond_footerを削除.

  // ファクトリーの削除.
  delete first; // deleteでfirstを削除.
  delete second; // deleteでsecondを削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
