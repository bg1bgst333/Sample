/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int x;
  int ret;

  /* 入力受付を繰り返す. */
  while (1){
    printf("x: ");
    ret = scanf("%d", &x);
    if (ret > 0){
      printf("x = %d\n", x);
    }
    else if (ret == 0){
      printf("x read failed!\n");
      if (feof(stdin)){
        printf("feof\n");
      }
      if (ferror(stdin)){
        printf("ferror\n");
      }
      return 1;
    }
    else if (ret == EOF){
      printf("x read error!\n");
      if (feof(stdin)){
        printf("feof\n");
      }
      if (ferror(stdin)){
        printf("ferror\n");
      }
      return 2;
    }
  }

}
