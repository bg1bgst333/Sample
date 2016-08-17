// ヘッダのインクルード
#include <cstdio> // C標準入出力

// main関数の定義
int main(void){

  // 変数の宣言と初期化.
  char c1 = 127; // char型変数c1を127で初期化.
  int i1 = 100; // int型変数i1を100で初期化.
  float f1 = 12.3; // float型変数f1を12.3で初期化.
  double d1 = 123.456789987654321; // double型変数d1を123.456789987654321で初期化.
  char c2; // char型変数c2.
  int i2; // int型変数i2.
  float f2; // float型変数f2.
  double d2; // double型変数d2.

  // C言語スタイルのキャスト演算子で違う型にキャスト.(暗黙の型変換が可能な場合なのでキャスト演算子を付ける必要は無いのだが, キャストを明示するために付けている.)
  f2 = (float)d1; // d1をf2に代入(doubleからfloatへのキャスト.)
  printf("f2 = %f\n", f2); // printfでf2を出力.
  i2 = (int)f1; // f1をi2に代入(floatからintへのキャスト.)
  printf("i2 = %d\n", i2); // printfでi2を出力.
  c2 = (char)i1; // i1をc2に代入(intからcharへのキャスト.)
  printf("c2 = %x\n", c2); // printfでc2を出力.
  d2 = (double)c1; // c1をd2に代入(charからdoubleへのキャスト.)
  printf("d2 = %lf\n", d2); // printfでd2を出力.

  // 改行
  printf("\n"); // printfで改行.
 
  // C++スタイルのキャスト演算子で違う型にキャスト.(C言語と同じようにキャストできるのにこれを使う目的は, これ以外のキャストのパターンと明確に分けるためなのでこれを使う.)
  f2 = static_cast<float>(d1); // d1をf2に代入(doubleからfloatへのstatic_cast.)
  printf("f2 = %f\n", f2); // printfでf2を出力.
  i2 = static_cast<int>(f1); // f1をi2に代入(floatからintへのstatic_cast.)
  printf("i2 = %d\n", i2); // printfでi2を出力.
  c2 = static_cast<char>(i1); // i1をc2に代入(intからcharへのstatic_cast.)
  printf("c2 = %x\n", c2); // printfでc2を出力.
  d2 = static_cast<double>(c1); // c1をd2に代入(charからdoubleへのstatic_cast.)
  printf("d2 = %lf\n", d2); // printfでd2を出力.

  // プログラムの終了
  return 0;

}
