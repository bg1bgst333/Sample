/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* グローバル変数の初期化. */
int x = 10; /* xを10に初期化. */

/* 関数のプロトタイプ宣言 */
void func(void); /* 関数funcのプロトタイプ宣言. */

/* main関数の定義 */
int main(void){

  /* ローカル変数の初期化 */
  int x = 20; /* xを20に初期化. */

  /* xの値を出力. */
  printf("x = %d\n", x); /* printfでxを出力. */

  /* if文ブロックで変数の初期化. */
  if (x == 20){ /* xが20なら. */

    /* 変数の初期化. */
    int x = 30; /* xを30に初期化. */

    /* xの値を出力. */
    printf("x = %d\n", x); /* printfでxを出力. */

    /* 単独のブロックで変数の初期化. */
    {

      /* 変数の初期化. */
      int x = 40; /* xを40に初期化. */

      /* xの値を出力. */
      printf("x = %d\n", x); /* printfでxを出力. */

    }

    /* xの値を出力. */
    printf("x = %d\n", x); /* printfでxを出力. */

  }

  /* funcを呼ぶ. */
  func(); /* funcを実行. */

  /* xの値を出力. */
  printf("x = %d\n", x); /* printfでxを出力. */

  /* プログラムの終了. */
  return 0;

}

/* 関数funcの定義. */
void func(void){

  /* xの出力. */
  printf("x = %d\n", x); /* printfでxを出力. */

}
