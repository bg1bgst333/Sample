/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列操作 */

/* 関数のプロトタイプ宣言 */
void func(void *ptr, int size); /* void型ポインタを受け取る関数func. */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int x; /* int型変数x */
  char str[16]; /* char型配列str(要素数16) */

  /* int型変数に何かを格納してもらう. */
  func(&x, sizeof(x)); /* funcにint型変数xとサイズを渡す. */

  /* xの出力 */
  printf("x = %d\n", x); /* printfでxを出力. */

  /* char型配列に何かを格納してもらう. */
  func((void *)str, sizeof(str)); /* funcにchar型配列strとサイズを渡す. */

  /* strの出力 */
  printf("str = %s\n", str); /* printfでstrを出力. */

  /* プログラムの終了 */
  return 0;

}

/* 関数funcの定義. */
void func(void *ptr, int size){ /* void型ポインタとサイズを受け取る. */

  /* サイズを確認. */
  if (size == 4){ /* 4の場合, intとする. */
    *((int *)ptr) = 123; /* ptrをint *型にキャストして参照先に123を格納. */
  }
  else if (size > 8){ /* 8より大きい場合, char型配列とする. */
    strcpy((char *)ptr, "ABCDE"); /* ptrをchar *型にキャストして, strcpyで"ABCDE"をセット. */
  }

}
