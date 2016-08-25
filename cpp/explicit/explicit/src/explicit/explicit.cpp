// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "test1.h" // クラスclass_test1
#include "test2.h" // クラスclass_test2
#include "test3.h" // クラスclass_test3
#include "test4.h" // クラスclass_test4

// main関数の定義
int main(void){

  // オブジェクトの初期化
  class_test1 obj1(10); // obj1に引数形式で10を渡して生成.
  class_test1 obj2 = 20; // obj2に初期化形式で20を渡して生成.
  class_test2 obj3(30); // obj3に引数形式で30を渡して生成.
  //class_test2 obj4 = 40; // obj4に初期化形式で40を渡して生成.(class_test2の引数付きコンストラクタはexplicitが付いているので, これはできない.)
  class_test3 obj5(obj1); // obj5に引数形式でobj1を渡して生成.
  class_test3 obj6 = obj2; // obj6に初期化式でobj2を渡して生成.
  class_test3 obj7(30); // obj7に引数形式で30を渡して生成.(暗黙的にclass_test1のオブジェクトが生成され, それに30が渡され, そのオブジェクトがobj7に渡される.)
  //class_test3 obj8 = 40; // obj8に初期化形式で40を渡して生成.(このように直接的に渡すことはできない模様.)
  class_test4 obj9(obj3); // obj9に引数形式でobj3を渡して生成.
  //class_test4 obj10 = obj3; // obj10に初期化形式でobj3を渡して生成.(class_test4の引数付きコンストラクタはexplicitが付いているので, これはできない.)
  //class_test4 obj11(40); // obj11に引数形式で40を渡して生成.(class_test2の引数付きコンストラクタはexplicitが付いているので, 暗黙的にclass_test2のオブジェクトを生成できない.)
  //class_test4 obj12 = 50; // obj12に初期化形式で50を渡して生成.(このように直接的に渡すことはできない模様.)

  // 出力
  obj1.show(); // obj1.showで出力.
  obj2.show(); // obj2.showで出力.
  obj3.show(); // obj3.showで出力.
  //obj4.show(); // obj4.showで出力.
  obj5.show(); // obj5.showで出力.
  obj6.show(); // obj6.showで出力.
  obj7.show(); // obj7.showで出力.
  //obj8.show(); // obj8.showで出力.
  obj9.show(); // obj9.showで出力.
  //obj10.show(); // obj10.showで出力.
  //obj11.show(); // obj11.showで出力.
  //obj12.show(); // obj12.showで出力.

  // プログラムの終了
  return 0;

}
