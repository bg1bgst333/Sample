// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "square_root.h" // クラスclass_square_root

// main関数の定義
int main(void){

  // 変数・オブジェクトの宣言.
  class_square_root csr(3.0, 4.0); // class_square_rootオブジェクトcsrのコンストラクタに幅3.0, 高さ4.0を渡す.
  double d = 0.0; // double型変数dを0.0に初期化.

  // ユーザ定義型変換で平方根を取得.
  d = (double)csr; // csrをdoubleでキャスト.(これでユーザ定義型変換が呼ばれる. 変数がdoubleなので本来明示的なキャストは不要だが今回はあえて付けている.)

  // 平方根を出力.
  std::cout << "d = " << d << std::endl; // dを出力.

  // プログラムの終了
  return 0;

}
