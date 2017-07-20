// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "iterator.h" // class_iterator

// main関数
int main(){

  // オブジェクトの宣言.
  class_array *array_ptr = NULL; // array_ptrをNULLで初期化.
  class_iterator *iterator_ptr = NULL; // iterator_ptrをNULLで初期化.
  class_iterator *iterator_ptr2 = NULL; // iterator_ptr2をNULLで初期化.

  // class_arrayオブジェクトの生成.
  array_ptr = new class_array(3); // 要素数3のclass_arrayオブジェクトを生成し, ポインタをarray_ptrに格納.

  // class_iteratorオブジェクトの生成.(要素のセット用.)
  iterator_ptr = new class_iterator(array_ptr); // array_ptrを走査するイテレータiterator_ptrに格納.

  // class_iteratorオブジェクトの生成.(要素の取得用.)
  iterator_ptr2 = new class_iterator(array_ptr); // array_ptrを走査するイテレータiterator_ptr2に格納.

  // 値のセット.
  iterator_ptr->current()->set_name("Taro"); // "Taro"をセット.
  iterator_ptr->current()->set_num(1); // 1をセット.
  iterator_ptr->next(); // 次へ
  iterator_ptr->current()->set_name("Jiro"); // "Jiro"をセット.
  iterator_ptr->current()->set_num(2); // 2をセット.
  iterator_ptr->next(); // 次へ
  iterator_ptr->current()->set_name("Saburo"); // "Saburo"をセット.
  iterator_ptr->current()->set_num(3); // 3をセット.

  // 値の取得と出力.
  while (iterator_ptr2->current() != iterator_ptr2->end()){ // currentがendになるまで.

    // 取得して出力.
    std::cout << iterator_ptr2->current()->get_name() << std::endl; // get_nameで取得して出力.
    std::cout << iterator_ptr2->current()->get_num() << std::endl; // get_numで取得して出力.
    iterator_ptr2->next(); // 次へ.

  }

  // iterator_ptr2の削除
  delete iterator_ptr2; // deleteでiterator_ptr2を削除.

  // iterator_ptrの削除.
  delete iterator_ptr; // deleteでiterator_ptrを削除.

  // array_ptrの削除.
  delete array_ptr; // deleteでarray_ptrを削除.

  // プログラムの終了.
  return 0; // 0を返して正常終了.

}
