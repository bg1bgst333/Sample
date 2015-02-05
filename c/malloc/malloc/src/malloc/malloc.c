/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int count; /* 動的確保するint型配列の要素数として入力された整数値を格納するint型変数count. */
  int *int_array; /* mallocで動的確保されたint型配列の先頭アドレスを指すポインタ. */
  int i; /* ループ用変数i */

  /* 動的確保する配列の要素数countの入力. */
  printf("count: "); /* countの入力フォーム */
  scanf("%d", &count); /* 入力された要素数をcountに格納. */

  /* 要素数countとなる配列のメモリを動的確保. */
  int_array = (int *)malloc(sizeof(int) * count); /* mallocで要素数count分の配列を動的確保し, そのポインタをint_arrayに格納.(mallocの戻り値は(void *)なので(int *)にキャスト.) */

  /* 各要素に値を入力する. */
  for (i = 0; i < count; i++){ /* count分繰り返し. */

    /* 値を入力. */
    printf("int_array[%d]: ", i); /* int_array[i]の入力フォーム */
    scanf("%d", int_array + i); /* i番目に入力された値を格納. */

  }

  /* 1行空ける. */
  printf("\n"); /* "\n"で1行空ける. */

  /* 各要素の出力 */
  for (i = 0; i < count; i++){ /* count分繰り返し. */

    /* 値を出力. */
    printf("int_array[%d] = %d\n", i, *(int_array + i)); /* int_array[i]の値を出力. */

  }

  /* 動的確保した配列のメモリを解放. */
  free(int_array); /* freeでint_arrayのメモリを解放. */

  /* プログラムの終了 */
  return 0;

}
