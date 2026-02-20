/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int ret_e;

  /* 標準出力が閉じられている時, printfは失敗する. */
  fclose(stdout);
  ret_e = printf("ABCDE\n");
  if (ret_e < 0){ /* 戻り値が負の値の場合は失敗. */
    perror("printf");
  }
  else{
    printf("NO ERROR\n");
  }

  /* プログラムの終了 */
  return 0;

}
