/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* ポインタの宣言 */
  FILE *fp;

  /* ファイルを開く. */
  fp = fopen("test.txt", "r");
  if (fp == NULL){
    return 1;
  }

  /* FILE構造体のポインタを取得出来たので, FILE構造体のメンバ_flagsの_IO_EOF_SEENの部分を出力してみる. */
  printf("(fp->_flags & _IO_EOF_SEEN) >> 4 = %x\n", (fp->_flags & _IO_EOF_SEEN) >> 4);

  /* ファイルを閉じる. */
  fclose(fp);

  /* プログラムの終了 */
  return 0; 

}
