/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  float result_normal; /* キャスト演算子を使わず計算した結果. */
  float result_cast; /* キャスト演算子を使って計算した結果. */

  /* キャスト演算子を使わない場合. */
  result_normal = 2 / 5; /* 整数同士の割り算と扱われ, 0となり, 代入先がfloatなので暗黙キャストにより0.000000となってresult_normalに渡される. */

  /* キャスト演算子を使う場合. */
  result_cast = (float)2 / (float)5; /* 浮動小数にしたもの同士の割り算として扱われ, 0.400000となり, 暗黙キャストする必要なくresult_castに渡される. */

  /* 結果 */
  printf("result_normal = %f\n", result_normal); /* result_normalの値を出力. */
  printf("result_cast = %f\n", result_cast); /* result_castの値を出力. */
 
  /* プログラムの終了 */
  return 0;

}
