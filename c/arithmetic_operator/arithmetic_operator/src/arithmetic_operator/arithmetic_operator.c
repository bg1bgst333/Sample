/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int a; /* int型変数a */
  int b; /* int型変数b */
  int add_result; /* 加算の結果を格納するint型変数add_result. */
  int sub_result; /* 減算の結果を格納するint型変数sub_result. */
  int mul_result; /* 乗算の結果を格納するint型変数mul_result. */
  int div_result; /* 除算の結果を格納するint型変数div_result. */
  int mod_result; /* 剰余算の結果を格納するint型変数mod_result. */

  /* aとbの入力 */
  printf("a: "); /* aの入力フォーム */
  scanf("%d", &a); /* 入力された整数値をaに格納. */
  printf("b: "); /* bの入力フォーム */
  scanf("%d", &b); /* 入力された整数値をbに格納. */

  /* 加算 */
  add_result = a + b; /* aとbを'+'演算子で加算し, 結果をadd_resultに格納. */
  /* 減算 */
  sub_result = a - b; /* aとbを'-'演算子で減算し, 結果をsub_resultに格納. */
  /* 乗算 */
  mul_result = a * b; /* aとbを'*'演算子で乗算し, 結果をmul_resultに格納. */
  /* 除算 */
  div_result = a / b; /* aとbを'/'演算子で除算し, 結果をdiv_resultに格納. */
  /* 剰余算 */
  mod_result = a % b; /* aとbを'%'演算子で剰余算し, 結果をmod_resultに格納. */

  /* 結果 */
  printf("a + b = %d + %d = %d\n", a, b, add_result); /* 加算の結果add_resultを出力. */
  printf("a - b = %d - %d = %d\n", a, b, sub_result); /* 減算の結果sub_resultを出力. */
  printf("a * b = %d * %d = %d\n", a, b, mul_result); /* 乗算の結果mul_resultを出力. */
  printf("a / b = %d / %d = %d\n", a, b, div_result); /* 除算の結果div_resultを出力. */
  printf("a %% b = %d %% %d = %d\n", a, b, mod_result); /* 剰余算の結果mod_resultを出力. */

  /* プログラムの終了 */
  return 0;

}
