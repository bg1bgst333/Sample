/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <openssl/bio.h> /* BIO */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  BIO *buffer = NULL; /* バッファ用フィルタBIOへのポインタbufferをNULLに初期化. */

  /* バッファ用フィルタBIOの作成. */
  buffer = BIO_new(BIO_f_buffer()); /* BIO_newにBIO_f_buffer()の戻り値を渡すことでバッファ用フィルタBIOを作成. */

  /* bufferを出力. */
  printf("buffer = %08x\n", buffer); /* printfでbufferを出力. */

  /* バッファ用フィルタBIOの解放. */
  BIO_free(buffer); /* BIO_freeでbufferを解放. */

  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
