// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // 標準入出力
#include <memory> // メモリ管理

// main関数
int main(){

  // shared_ptrの生成.
  std::shared_ptr<class_test> p1(new class_test(10)); // class_testオブジェクトポインタをshared_ptrのp1に渡す.
  std::shared_ptr<class_test> p2; // shared_ptrのp2を宣言.

  // p1の値を出力.
  p1->print(); // p1->printでp1の値を出力.

  // 参照カウンタの出力.
  std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // p1.use_countの結果を出力.

  // 改行.
  std::cout << std::endl; // std::endlで改行.

  // p1をp2にコピー.
  p2 = p1; // shared_ptrはコピー可能.

  // 値と参照カウンタを出力.
  p1->print(); // p1->printで値を出力.
  std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // p1.use_countの結果を出力.
  p2->print(); // p2->printで値を出力.
  std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // p2.use_countの結果を出力.

  // 改行.
  std::cout << std::endl; // std::endlで改行.

  // ブロックにp3を宣言.
  {

    // share_ptrの生成.
    std::shared_ptr<class_test> p3; // shared_ptrのp3を宣言.

    // p3にコピー.
    p3 = p1; // p1をp3にコピー.

    // p2の値を変更.
    p2->set(20); // p2->setで20に変更.

    // 値と参照カウンタを出力.
    p1->print(); // p1->printで値を出力.
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // p1.use_countの結果を出力.
    p2->print(); // p2->printで値を出力.
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // p2.use_countの結果を出力.
    p3->print(); // p3->printで値を出力.
    std::cout << "p3.use_count() = " << p3.use_count() << std::endl; // p3.use_countの結果を出力.

  }

  // 改行.
  std::cout << std::endl; // std::endlで改行.

  // 参照カウンタを出力.
  std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // p1.use_countの結果を出力.
  std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // p2.use_countの結果を出力.

  // 改行.
  std::cout << std::endl; // std::endlで改行.

  // p1の所有権を放棄.
  p1.reset();

  // p2だけが残るので, 値と参照カウンタを出力.
  p2->print(); // p2->printで値を出力.
  std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // p2.use_countの結果を出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
