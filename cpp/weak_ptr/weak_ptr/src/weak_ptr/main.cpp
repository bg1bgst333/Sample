// ヘッダのインクルード
// 独自のヘッダ
#include "test.h" // クラスclass_test
// 既定のヘッダ
#include <iostream> // 標準入出力
#include <memory> // メモリ管理

// main関数
int main(){

  // share_ptrの生成.
  std::shared_ptr<class_test> p1(new class_test(10)); // class_testオブジェクトポインタをshared_ptrのp1に渡す.
  std::shared_ptr<class_test> p2(new class_test(20)); // class_testオブジェクトポインタをshared_ptrのp2に渡す.
  //std::shared_ptr<class_test> p3(new class_test(30)); // class_testオブジェクトポインタをshared_ptrのp3に渡す.

  // 子ポインタをp3にする.(この場合は, p1からp3までの全てのデストラクタが呼ばれる.)
  //p1->ptr_ = p3; // p1->ptr_にp3をセット.
  //p2->ptr_ = p3; // p2->prt_にp3をセット.

  // p1の子ポインタをp2, p2の子ポインタをp1にする.(ptr_をweak_ptrにしたことで, 所有権を持たなくなったので, デストラクタが呼ばれる.)
  p1->ptr_ = p2; // p1->ptr_にp2をセット.
  p2->ptr_ = p1; // p2->ptr_にp1をセット.

  // weak_ptrの値を出力.
  std::shared_ptr<class_test> wp2 = p1->ptr_.lock(); // p1->ptr_.lockでp1->ptr_にアクセス.(p1->ptr_はp2なのでwp2に格納.)
  std::shared_ptr<class_test> wp1 = p2->ptr_.lock(); // p2->ptr_.lockでp2->ptr_にアクセス.(p2->ptr_はp1なのでwp1に格納.)
  wp2->print(); // wp2->printで出力.
  wp1->print(); // wp1->printで出力.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
