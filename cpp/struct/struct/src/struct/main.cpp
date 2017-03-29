// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "struct_test.h" // テスト構造体
#include "class_test.h" // テストクラス

// main関数の定義
int main(){

  // オブジェクトの宣言
  struct_test st; // struct_test構造体オブジェクトst.
  class_test ct; // class_test構造体オブジェクトct.

  // 構造体へのアクセス.
  st.num = 10; // st.numに10を代入.
  st.show(); // st.showで出力.

  // クラスへのアクセス.
  ct.num = 20; // ct.numに20を代入.
  ct.show(); // ct.showで出力.
 
  // プログラムの終了
  return 0;

}
