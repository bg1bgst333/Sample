/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列操作 */

/* 関数のプロトタイプ宣言 */
void create(char **ptr); /* 動的配列を作成し, 初期文字列を入れる関数createの宣言. */
void destroy(char **ptr); /* 動的配列を破棄する関数destroyの宣言. */

/* main関数の定義 */
int main(void){

  /* ポインタへのポインタの宣言と, ポインタの初期化. */
  int **ptr_to_ptr; /* int型ポインタへのポインタptr_to_ptr. */
  int i; /* ループ用変数i */
  int j; /* ループ用変数j */
  char *buf_ptr = NULL; /* 文字列を格納するバッファへのポインタbuf_ptr(自ら確保する必要はない.). */

  /* int型ポインタ動的配列の生成. */
  ptr_to_ptr = (int **)malloc(sizeof(int *) * 5); /* mallocでint型ポインタ動的配列(要素数5)を生成し, 戻り値のポインタはptr_to_ptrに格納. */
  /* int型動的配列生成し, そのポインタをint型ポインタ動的配列の各要素に格納. */
  for (i = 0; i < 5; i++){ /* 0から4まで5回繰り返す. */
    *(ptr_to_ptr + i) = (int *)malloc(sizeof(int) * 5); /* mallocでint型動的配列(要素数5)を生成し, 戻り値のポインタはptr_to_ptrに格納. */
  }

  /* 各要素への値の代入. */
  for (i = 0; i < 5; i++){ /* iが0から4まで5回繰り返す. */
    for (j = 0; j < 5; j++){ /* jが0から4まで5回繰り返す. */
      *(*(ptr_to_ptr + i) + j) = 5 * i + j; /* 5 * i + jを格納. */
    }
  }

  /* 各要素の値を出力. */
  for (i = 0; i < 5; i++){ /* iが0から4まで5回繰り返す. */
    for (j = 0; j < 5; j++){ /* jが0から4まで5回繰り返す. */
      printf("*(*(ptr_to_ptr + %d) + %d) = %d\n", i, j, *(*(ptr_to_ptr + i) + j)); /* *(*(ptr_to_ptr + i) + j)を出力. */
    }
  }

  /* 動的配列の破棄 */
  for (i = 0; i < 5; i++){ /* 0から4まで5回繰り返す. */
    free(*(ptr_to_ptr + i)); /* freeで*(ptr_to_ptr + i)を破棄. */
  }
  free(ptr_to_ptr); /* ポインタへのポインタを破棄. */ 

  /* 文字列の生成 */
  create(&buf_ptr); /* createにbuf_ptrのアドレスを渡す. */

  /* 文字列の出力 */
  printf("buf_ptr = %s\n", buf_ptr); /* printfでbuf_ptrを出力. */

  /* 文字列の破棄 */
  destroy(&buf_ptr); /* destroyにbuf_ptrのアドレス渡す. */

  /* プログラムの終了 */
  return 0;

}

/* 関数createの定義 */
void create(char **ptr){

  /* 動的配列の生成と文字列のセット. */
  *ptr = (char *)malloc(sizeof(char) * 6); /* mallocでNULL文字含めて6文字分入る動的配列を生成. */
  strcpy(*ptr, "ABCDE"); /* strcpyで*ptrに"ABCDE"をコピー. */

}

/* 関数destroyの定義 */
void destroy(char **ptr){

  /* 動的配列の破棄 */
  free(*ptr); /* freeで*ptrを破棄. */
  *ptr = NULL; /* *ptrをNULLで埋める. */

}
