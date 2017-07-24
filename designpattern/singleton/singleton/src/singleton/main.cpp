// ヘッダのインクルード
// 既定のヘッダ
#include <cstddef> // C++定義
// 独自のヘッダ
#include "singleton.h" // class_singleton

// main関数
int main(){

  // class_singletonオブジェクトを取得.
  class_singleton *singleton = class_singleton::get_instance(); // class_singleton::get_instanceでsingletonを取得.

  // countを出力.
  singleton->print(); // singleton->printでcountを出力.

  // class_singletonオブジェクトを取得.
  singleton = class_singleton::get_instance(); // class_singleton::get_instanceでsingletonを取得.

  // countを出力.
  singleton->print(); // singleton->printでcountを出力.

  // class_singletonオブジェクトの削除.
  class_singleton::delete_instance(); // class_singleton::delete_instanceで削除.

  // singletinは使えないのでNULLをセット(削除はclass_singleton内部で終了済み.)
  singleton = NULL; // singletonにNULLをセット.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
