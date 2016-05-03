/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int a; /* int型変数a */
  int b; /* int型変数b */
  int c; /* int型変数c */
  int d; /* int型変数d */
  int e; /* int型変数e */

  /* aの入力 */
  printf("a: "); /* aの入力フォーム */
  scanf("%d", &a); /* 入力された整数値をaに格納. */

  /* bの入力 */
  printf("b: "); /* bの入力フォーム */
  scanf("%d", &b); /* 入力された整数値をbに格納. */

  /* 論理和(OR)の演算子|| */
  if (a > 10 || b > 20){ /* aが10より大きいまたはbが20より大きい. */
    printf("(a > 10 || b > 20) is TRUE.\n"); /* "(a > 10 || b > 20) is TRUE."と出力. */
  }
  else{ /* そうでない時. */
    printf("(a > 10 || b > 20) is FALSE.\n"); /* "(a > 10 || b > 20) is FALSE."と出力. */
  }

  /* cの入力 */
  printf("c: "); /* cの入力フォーム */
  scanf("%d", &c); /* 入力された整数値をcに格納. */

  /* dの入力 */
  printf("d: "); /* dの入力フォーム */
  scanf("%d", &d); /* 入力された整数値をdに格納. */

  /* 論理積(AND)の演算子&& */
  if (c > 10 && d > 20){ /* cが10より大きいかつdが20より大きい. */
    printf("(c > 10 && d > 20) is TRUE.\n"); /* "(c > 10 && d > 20) is TRUE."と出力. */
  }
  else{ /* そうでない時. */
    printf("(c > 10 && d > 20) is FALSE.\n"); /* "(c > 10 && d > 20) is FALSE."と出力. */
  }

  /* eの入力 */
  printf("e: "); /* eの入力フォーム */
  scanf("%d", &e); /* 入力された整数値をeに格納. */

  /* 否定(NOT)の演算子! */
  if (!(e > 10)){ /* eが10より大きくない. */
    printf("(!(e > 10)) is TRUE.\n"); /* "(!(e > 10)) is TRUE."と出力. */
  }
  else{ /* そうでない時. */
    printf("(!(e > 10)) is FALSE.\n"); /* "(!(e > 10)) is FALSE."と出力. */
  }
 
  /* プログラムの終了 */
  return 0;

}

