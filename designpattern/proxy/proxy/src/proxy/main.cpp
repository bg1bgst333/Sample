// ヘッダのインクルード
// 独自のヘッダ
#include "simple_print.h" // class_simple_print
#include "simple_print_factory.h" // class_simple_print_factory
#include "proxy_print.h" // class_proxy_print

// main関数
int main(){

  // オブジェクトの生成.
  class_simple_print *simple_print = new class_simple_print(); // simple_printの生成.

  // 出力.
  simple_print->print("ABCDE"); // simple_print->printで"ABCDE"を出力.

  // オブジェクトの破棄.
  delete simple_print; // deleteでsimple_printを破棄.

  // 生成してプロキシに渡す.
  class_proxy_print proxy(new class_simple_print()); // proxyにnewでclass_simple_printオブジェクトポインタを渡す.

  // 出力.
  proxy.print("FGHIJ"); // proxy->printで"FGHIJ"を出力.
  proxy->print("KLM"); // proxy->printで"KLM"を出力.
  (*proxy).print("NOP"); // (*proxy).printで"NOP"を出力.

  // ファクトリー生成.
  class_simple_print_factory *factory = class_simple_print_factory::get_instance(); // factory取得.

  // ファクトリーから生成してプロキシに渡す.
  class_proxy_print proxy2(factory->create_simple_print()); // factory->create_simple_printをproxy2に渡す.

  // 出力.
  proxy2->print("VWXYZ"); // proxy2->printで"VWXYZ"を出力.

  // ファクトリー破棄.
  class_simple_print_factory::delete_instance(); // delete_instanceで破棄.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
