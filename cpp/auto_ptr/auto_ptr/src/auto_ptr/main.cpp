// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <memory> // メモリ管理

// main関数の定義
int main(){

  // auto_ptrの生成.
  std::auto_ptr<class_test> p1(new class_test(10)); // 初期値10のclass_testオブジェクトをnewで生成し, auto_ptrのp1のコピーコンストラクタに渡すことでp1を生成. 

  // p1の値を出力.
  p1->print(); // p1->printで出力.

  // p1の値を変更.
  p1->set(20); // p1->setで20をセット.

  // auto_ptrのコピー.
  std::auto_ptr<class_test> p2; // std::auto_ptr<class_test>型のp2を宣言.
  p2 = p1; // p1をp2にコピー.

  // p2の値を出力.
  p2->print(); // p2->printで出力.
  //p1->print(); // p2に所有権が移っているので, これを呼ぶとSegmentation fault.

  // 関数へ渡した場合のコピーと, 関数から戻り値を貰った場合のコピー.
  std::auto_ptr<class_test> p3; // std::auto_ptr<class_test>型のp3を宣言.
  p3 = func(p2); // p2をfuncに渡し, p3を貰う.

  // p3の値を出力.
  p3->print(); // p3->printで出力.
  //p2->print(); // p3に所有権が移っているので, これを呼ぶとSegmentation fault.

  // プログラムの終了
  return 0;

} // このスコープを抜けると, p3の指すメモリが解放される.
