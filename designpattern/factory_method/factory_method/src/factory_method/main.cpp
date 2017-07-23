// ヘッダのインクルード
// 既定のヘッダ
#include <cstddef> // C++定義
// 独自のヘッダ
#include "print_factory.h" // class_print_factory

// main関数
int main(){

  // オブジェクトの宣言.
  interface_factory *factory = NULL; // interface_factoryポインタfactoryをNULLで初期化.
  interface_product *product1 = NULL; // interface_productポインタproduct1をNULLで初期化.
  interface_product *product2 = NULL; // interface_productポインタproduct2をNULLで初期化.

  // ファクトリーの生成.
  factory = new class_print_factory(); // class_print_factoryオブジェクトポインタをfactoryに格納.
  product1 = factory->create_instance(TYPE_ABC); // factory->create_instanceにTYPE_ABCを渡して, ポインタはproduct1に格納.
  product2 = factory->create_instance(TYPE_DEF); // factory->create_instanceにTYPE_DEFを渡して, ポインタはproduct2に格納.

  // 各プロダクトの出力.
  product1->print(); // product1->printで出力.
  product2->print(); // product2->printで出力.

  // オブジェクトの削除.
  delete product2; // product2を削除.
  delete product1; // product1を削除.
  delete factory; // factoryを削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
