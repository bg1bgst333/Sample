/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int i; /* ループ変数i */
  int j; /* ループ変数j */

  /* 二重ループ */
  for (j = 0; j < 5; j++){ /* jが5ならこのループは終了. */
    for (i = 0; i < 5; i++){ /* iが5ならこのループは終了. */

      /* iとjの出力. */
      printf("i = %d, ", i); /* iを出力, */
      printf("j = %d\n", j); /* jを出力. */

      /* iが2なら二重ループから一気に抜ける. */
      if (i == 2){ /* iが2の時. */
        goto end; /* gotoでendに飛ぶ. */
      }

    }
  }

/* ラベルの設置 */
end: /* endラベル */
  printf("end\n"); /* "end"と出力. */
  
  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
