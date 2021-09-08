/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <openssl/bio.h> /* BIO */
#include <openssl/evp.h> /* EVP(BIO_f_base64) */
#include <openssl/err.h> /* エラー */
#include <openssl/buffer.h> /* バッファ */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  BIO *base64 = NULL; /* Base64フィルタBIOへのポインタbase64をNULLに初期化. */
  BIO *mem = NULL; /* メモリ用データシンクBIOへのポインタmemをNULLに初期化. */
  BUF_MEM *bptr = NULL; /* バッファメモリポインタbptrをNULLに初期化. */
  char *buf = NULL; /* 文字列バッファポインタbufをNULLに初期化. */

  /* Base64フィルタBIOの作成. */
  base64 = BIO_new(BIO_f_base64()); /* BIO_new()にBIO_f_base64()の戻り値を渡すことでBase64フィルタBIOのbase64を作成. */

  /* メモリ用データシンクBIOの作成. */
  mem = BIO_new(BIO_s_mem()); /* BIO_new()にBIO_s_mem()の戻り値を渡してメモリBIOのmemを作成. */
  
  /* base64とmemの連結. */
  base64 = BIO_push(base64, mem); /* BIO_pushでbase64とmemを連結. */

  /* base64に"ABCDE"を書き込む. */
  BIO_write(base64, "ABCDE", 5); /* BIO_writeでbase64に"ABCDE"を書き込む. */

  /* base64をフラッシュしてメモリに書き込まれる. */
  BIO_flush(base64); /* BIO_flushすることでbase64からmemに書き込まれる. */

  /* base64のバッファメモリポインタを取得. */
  BIO_get_mem_ptr(base64, &bptr); /* BIO_get_mem_ptrでbptrを取得. */

  /* 文字列バッファのメモリ確保. */
  buf = (char *)malloc(bptr->length); /* mallocでbptr->length分のメモリを確保し, ポインタをbufに格納. */

  /* 内容のコピー. */
  memcpy(buf, bptr->data, bptr->length - 1); /* memcpyでbptr->dataをbufにコピー. */

  /* '\0'終端. */
  buf[bptr->length - 1] = '\0'; /* 終端を'\0'で埋める. */

  /* bufの出力. */
  printf("buf = %s\n", buf); /* printfでbufを出力. */

  /* bufの解放. */
  free(buf); /* freeでbufを解放. */

  /* BIOの解放. */
  BIO_free_all(base64); /* base64とmemは連結しているのでBIO_free_allで全部解放される. */

  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
