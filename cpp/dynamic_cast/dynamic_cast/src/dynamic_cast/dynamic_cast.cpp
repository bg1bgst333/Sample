// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "base.h" // クラスclass_base
#include "derived1.h" // クラスclass_derived1
#include "derived2.h" // クラスclass_derived2

// main関数の定義
int main(void){

  // ポインタの宣言
  class_base *base_ptr = NULL; // class_baseオブジェクトポインタbase_ptrをNULLに初期化.
  class_derived1 *derived1_ptr = NULL; // class_derived1オブジェクトポインタderived1_ptrをNULLに初期化.
  class_derived2 *derived2_ptr = NULL; // class_derived2オブジェクトポインタderived2_ptrをNULLに初期化.
  class_base *upcast1_ptr = NULL; // class_baseオブジェクトポインタupcast1_ptrをNULLに初期化.
  class_base *upcast2_ptr = NULL; // class_baseオブジェクトポインタupcast2_ptrをNULLに初期化.
  class_derived1 *downcast1a_ptr = NULL; // class_derived1オブジェクトポインタdowncast1a_ptrをNULLに初期化.
  class_derived1 *downcast1b_ptr = NULL; // class_derived1オブジェクトポインタdowncast1b_ptrをNULLに初期化.
  class_derived2 *downcast2a_ptr = NULL; // class_derived2オブジェクトポインタdowncast2a_ptrをNULLに初期化.
  class_derived2 *downcast2b_ptr = NULL; // class_derived2オブジェクトポインタdowncast2b_ptrをNULLに初期化.

  // オブジェクト生成
  base_ptr = new class_base(); // class_baseオブジェクトを生成し, base_ptrに格納.
  derived1_ptr = new class_derived1(); // class_derived1オブジェクトを生成し, derived1_ptrに格納.
  derived2_ptr = new class_derived2(); // class_derived2オブジェクトを生成し, derived2_ptrに格納.

  // アップキャスト(派生クラスから基底クラスへのキャスト.)
  upcast1_ptr = (class_base *)derived1_ptr; // derived1_ptrをC言語キャストでclass_baseポインタにキャストして, upcast1_ptrに格納.
  upcast2_ptr = dynamic_cast<class_base *>(derived2_ptr); // derived2_ptrをdynamic_castでclass_baseポインタにキャストして, upcaste2_ptrに格納.

  // ダウンキャスト(基底クラスから派生クラスへのキャスト. アップキャストしたものを2つのクラスにそれぞれダウンキャストしてみる.)
  downcast1a_ptr = dynamic_cast<class_derived1 *>(upcast1_ptr); // upcast1_ptrをdynamic_castでclass_derived1ポインタにキャストして, downcast1a_ptrに格納.
  downcast1b_ptr = dynamic_cast<class_derived1 *>(upcast2_ptr); // upcast2_ptrをdynamic_castでclass_derived1ポインタにキャストして, downcast1b_ptrに格納.
  downcast2a_ptr = dynamic_cast<class_derived2 *>(upcast1_ptr); // upcast1_ptrをdynamic_castでclass_derived2ポインタにキャストして, downcast2a_ptrに格納.
  downcast2b_ptr = dynamic_cast<class_derived2 *>(upcast2_ptr); // upcast2_ptrをdynamic_castでclass_derived2ポインタにキャストして, downcast2b_ptrに格納.

  // メソッド呼び出し
  base_ptr->base_func(); // base_ptr->base_funcを呼び出し.
  derived1_ptr->derived1_func(); // derived1_ptr->derived1_funcを呼び出し.
  derived2_ptr->derived2_func(); // derived2_ptr->derived2_funcを呼び出し.
  upcast1_ptr->base_func(); // upcast1_ptr->base_funcを呼び出し.
  if (upcast2_ptr == NULL){ // upcast2_ptrがNULLなら.
    std::cout << "dynamic_cast failed!" << std::endl; // "dynamic_cast failed!"と出力.
  }
  else{
    upcast2_ptr->base_func(); // upcast2_ptr->base_funcを呼び出し.
    std::cout << "dynamic_cast success!" << std::endl; // "dynamic_cast success!"と出力.
  }
  std::cout << std::endl; // 改行.
  if (downcast1a_ptr == NULL){ // downcast1a_ptrがNULL.
    std::cout << "1a failed!" << std::endl; // "1a failed!"と出力.
  }
  else{
    downcast1a_ptr->derived1_func(); // downcast1a_ptr->derived1_funcを呼ぶ.
    std::cout << "1a success!" << std::endl; // "1a success!"と出力.
  }
  if (downcast1b_ptr == NULL){ // downcast1b_ptrがNULL.
    std::cout << "1b failed!" << std::endl; // "1b failed!"と出力.
  }
  else{
    downcast1b_ptr->derived1_func(); // downcast1b_ptr->derived1_funcを呼ぶ.
    std::cout << "1b success!" << std::endl; // "1b success!"と出力.
  }
  if (downcast2a_ptr == NULL){ // downcast2a_ptrがNULL.
    std::cout << "2a failed!" << std::endl; // "2a failed!"と出力.
  }
  else{
    downcast2a_ptr->derived2_func(); // downcast2a_ptr->derived2_funcを呼ぶ.
    std::cout << "2a success!" << std::endl; // "2a success!"と出力.
  }
  if (downcast2b_ptr == NULL){ // downcast2b_ptrがNULL.
    std::cout << "2b failed!" << std::endl; // "2b failed!"と出力.
  }
  else{
    downcast2b_ptr->derived2_func(); // downcast2b_ptr->derived2_funcを呼ぶ.
    std::cout << "2b success!" << std::endl; // "2b success!"と出力.
  }

  // オブジェクト破棄
  delete base_ptr; // base_ptrを破棄.
  delete derived1_ptr; // derived1_ptrを破棄.
  delete derived2_ptr; // derived2_ptrを破棄.

  // プログラムの終了
  return 0;

}
