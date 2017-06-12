/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <openssl/bio.h> /* BIO */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  BIO *mem = NULL; /* メモリ用データシンクBIOへのポインタmemをNULLに初期化. */
  char buf[128] = {0}; /* char型配列buf(要素数128)を0で初期化. */

  /* メモリ用データシンクBIOの作成. */
  mem = BIO_new(BIO_s_mem()); /* BIO_new()にBIO_s_mem()の戻り値を渡してメモリBIOのmemを作成. */

  /* "ABCDE"をmemに書き込み. */
  BIO_write(mem, "ABCDE", 5); /* BIO_writeで"ABCDE"をmemに書き込み. */

  /* いったんフラッシュ. */
  BIO_flush(mem); /* BIO_flushでmemをフラッシュ. */

  /* "XYZ"をmemに書き込み. */
  BIO_write(mem, "XYZ", 3); /* BIO_writeで"XYZ"をmemに書き込み. */

  /* もう一度フラッシュ. */
  BIO_flush(mem); /* BIO_flushでmemをフラッシュ. */

  /* memの内容を読み込み. */
  BIO_read(mem, buf, 128); /* BIO_readでmemの内容をbufに読み込み. */

  /* bufの出力. */
  printf("buf = %s\n", buf); /* printfでbufを出力. */

  /* memの解放. */
  BIO_free(mem); /* BIO_freeでmemを解放. */

  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
