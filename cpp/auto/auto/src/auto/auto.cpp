// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <vector> // ベクタ
// 独自のヘッダ
#include "test.h" // クラスclass_test

// main関数の定義
int main(){

  // 変数の推論.
  auto i = 10; // iを10で初期化.(autoでiの型をintと推論.)
  auto s = "ABCDE"; // sを"ABCDE"で初期化.(autoでsの型をconst char *と推論.)

  // オブジェクトの推論.
  auto p = new class_test(100); // class_testオブジェクトを100で初期化.(autoでpの型をclass_test *と推論.)
  class_test o(200); // class_testオブジェクトoを200で初期化.(ポインタではなくオブジェクトを作成.)
  auto po = &o; // oのアドレスをpoに格納.(autoでpoの型をclass_test *と推論.(&を付けてるのでポインタと判断.))
  auto &ro = o; // roにoの参照を渡す.(autoに&を付けているので, class_test &と推論.)
  auto co = o; // coにoをコピー.(coにもoにも&がないので, class_testと推論.) 

  // 出力
  std::cout << "i = " << i << std::endl; // iを出力.
  std::cout << "s = " << s << std::endl; // sを出力.
  p->print(); // p->printで出力.
  o.print(); // o.printで出力.
  po->print(); // po->printで出力.
  ro.print(); // ro.printで出力.
  co.print(); // co.printで出力.

  // 改行
  std::cout << std::endl;

  // 値のセット.
  po->set(300); // po->setで300をセット.

  // 出力
  o.print(); // o.printで出力.
  po->print(); // po->printで出力.
  ro.print(); // ro.printで出力.
  co.print(); // co.printで出力.

  // 改行
  std::cout << std::endl;

  // 値のセット.
  ro.set(400); // ro.setで400をセット.

  // 出力
  o.print(); // o.printで出力.
  po->print(); // po->printで出力.
  ro.print(); // ro.printで出力.
  co.print(); // co.printで出力.

  // 改行
  std::cout << std::endl;

  // 値のセット.
  co.set(500); // co.setで500をセット.

  // 出力
  o.print(); // o.printで出力.
  po->print(); // po->printで出力.
  ro.print(); // ro.printで出力.
  co.print(); // co.printで出力.

  // 改行
  std::cout << std::endl;

  // イテレータの推論.
  std::vector<int> vec; // std::vector<int>型vec
  vec.push_back(10); // vec.push_backで10を追加.
  vec.push_back(20); // vec.push_backで20を追加.
  vec.push_back(30); // vec.push_backで30を追加.
  for (auto itor = vec.begin(); itor != vec.end(); itor++){ // vec.begin()からitorをstd::vector<int>::iteratorと推論.

    // itorの指す参照先の出力.
    std::cout << "*itor = " << *itor << std::endl; // *itorを出力.

  }
  
  // 解放.
  delete p; // pの指すメモリを解放.

  // プログラムの終了
  return 0;

}
