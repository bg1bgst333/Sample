// ヘッダのインクルード
// 独自のヘッダ
#include "framed_string_factory.h" // class_framed_string_factory

// main関数
int main(){

  // ファクトリーの取得.
  class_framed_string_factory *factory = class_framed_string_factory::get_instance(); // factory取得.

  // 枠付き文字列の取得.
  class_framed_string *framed_string1 = factory->get_framed_string("ABCDE"); // framed_string1の取得.

  // 枠付き文字列の出力.
  framed_string1->print(); // framed_string1->printで出力.

  // 枠付き文字列の取得.
  class_framed_string *framed_string2 = factory->get_framed_string("ABCDE"); // framed_string2の取得.

  // 枠付き文字列の出力.
  framed_string2->print(); // framed_string2->printで出力.

  // 枠付き文字列の取得.
  class_framed_string *framed_string3 = factory->get_framed_string("XYZ"); // framed_string3の取得.

  // 枠付き文字列の出力.
  framed_string3->print(); // framed_string3->printで出力.

  // ファクトリーの破棄.
  class_framed_string_factory::delete_instance(); // delete_instanceで破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
