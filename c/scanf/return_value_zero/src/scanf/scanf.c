/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数・配列の宣言 */
  int n;
  int ret_1;

  /* 入力値が整数1つを想定. */
  printf("n: ");
  ret_1 = scanf("%d", &n);
  printf("n = %d\n", n);
  printf("ret_1 = %d\n", ret_1);
  if (ret_1 == 0){ /* 0の場合は1つも読み込めなかった. */
    printf("n read failed!\n");
    return 1;
  }
  else if (ret_1 > 0){ /* 正の値なら読み込めた. */
    printf("n read success!\n");
    return 0; /* 正常終了 */
  }
  else{ /* 負の値は別のエラー. */
    printf("n read error!\n");
    return 2;
  }

}
