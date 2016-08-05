// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
#include <typeinfo> // 型情報
// 独自のヘッダ
#include "base.h" // クラスclass_base
#include "derived1.h" // クラスclass_derived1
#include "derived2.h" // クラスclass_derived2

// main関数の定義
int main(void){

  // オブジェクトポインタの宣言.
  class_base *base_ptr1; // class_base型ポインタbase_ptr1.
  class_base *base_ptr2; // class_base型ポインタbase_ptr2.
  class_base *base_ptr3; // class_base型ポインタbase_ptr3.
  class_derived1 *derived1_ptr; // class_derived1型ポインタderived1_ptr.
  class_derived2 *derived2_ptr; // class_derived2型ポインタderived2_ptr.

  // オブジェクトの生成.
  base_ptr1 = new class_base(); // class_baseを生成し, ポインタはbase_ptr1に格納.
  base_ptr2 = new class_derived1(); // class_derived1を生成し, ポインタはbase_ptr2に格納.
  base_ptr3 = new class_derived2(); // class_derived2を生成し, ポインタはbase_ptr3に格納.
  derived1_ptr = new class_derived1(); // class_derived1を生成し, ポインタはderived1_ptrに格納.
  derived2_ptr = new class_derived2(); // class_derived2を生成し, ポインタはderived2_ptrに格納.
 
  // typeid演算子でtype_infoを取得し, 型の名前を取得.(typeid(*ポインタ).name()という形で呼ばないとコンパイルエラーになるので注意.)
  std::cout << typeid(*base_ptr1).name() << std::endl; // typeid(*base_ptr1).nameで名前を取得し, 出力.
  std::cout << typeid(*base_ptr2).name() << std::endl; // typeid(*base_ptr2).nameで名前を取得し, 出力.
  std::cout << typeid(*base_ptr3).name() << std::endl; // typeid(*base_ptr3).nameで名前を取得し, 出力.
  std::cout << typeid(*derived1_ptr).name() << std::endl; // typeid(*derived1_ptr).nameで名前を取得し, 出力.
  std::cout << typeid(*derived2_ptr).name() << std::endl; // typeid(*derived2_ptr).nameで名前を取得し, 出力.

  // 改行
  std::cout << std::endl; // 改行を出力.

  // メッセージを表示.
  base_ptr1->print_message(); // base_ptr1->print_messageでメッセージを出力.
  base_ptr2->print_message(); // base_ptr2->print_messageでメッセージを出力.
  base_ptr3->print_message(); // base_ptr3->print_messageでメッセージを出力.
  derived1_ptr->print_message(); // derived1_ptr->print_messageでメッセージを出力.
  derived2_ptr->print_message(); // derived2_ptr->print_messageでメッセージを出力.

  // オブジェクトの破棄.
  delete base_ptr1; // base_ptr1を解放.
  delete base_ptr2; // base_ptr2を解放.
  delete base_ptr3; // base_ptr3を解放.
  delete derived1_ptr; // derived1_ptrを解放.
  delete derived2_ptr; // derived2_ptrを解放.

  // プログラムの終了.
  return 0;

}

