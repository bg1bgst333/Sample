/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <openssl/bio.h> /* BIO */
#include <openssl/evp.h> /* EVP(BIO_f_base64) */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  BIO *buffer = NULL; /* バッファ用フィルタBIOへのポインタbufferをNULLに初期化. */
  BIO *file = NULL; /* ファイル用データシンクBIOへのポインタfileをNULLに初期化. */
  BIO *base64 = NULL; /* Base64フィルタBIOへのポインタbase64をNULLに初期化. */

  /* ファイル用データシンクBIOの作成. */
  file = BIO_new_file("test.txt", "w"); /* 書き込み先のファイル用BIOポインタfileを作成. */
  if (file == NULL){ /* NULLなら */

    /* エラー処理 */
    ERR_print_errors_fp(stderr); /* ERR_print_errors_fpでエラー出力. */
    return -1; /* -1を返す. */

  }

  /* fileを出力. */
  printf("file = %08x\n", file); /* printfでfileを出力. */

  /* バッファ用フィルタBIOの作成. */
  buffer = BIO_new(BIO_f_buffer()); /* BIO_new()にBIO_f_buffer()の戻り値を渡すことでバッファ用フィルタBIOのbufferを作成. */

  /* bufferを出力. */
  printf("buffer = %08x\n", buffer); /* printfでbufferを出力. */

  /* Base64フィルタBIOの作成. */
  base64 = BIO_new(BIO_f_base64()); /* BIO_new()にBIO_f_base64()の戻り値を渡すことでBase64フィルタBIOのbase64を作成. */

  /* base64を出力. */
  printf("base64 = %08x\n", base64); /* printfでbase64を出力. */

  /* bufferとbase64とfileを連結. */
  BIO_push(buffer, base64); /* BIO_pushでbufferとbase64を連結. */
  BIO_push(base64, file); /* BIO_pushでbase64とfileを連結. */

  /* bufferに"ABCDE"を書き込む. */
  BIO_write(buffer, "ABCDE", 5); /* BIO_writeでbufferに"ABCDE"を書き込む. */

  /* バッファをフラッシュしてファイルに書き込まれる. */
  BIO_flush(buffer); /* BIO_flushすることでbufferからbase64を経由しfileにちゃんと書き込まれる. */

  /* BIOの解放. */
  BIO_free_all(buffer); /* bufferとbase64とfileは連結しているのでBIO_free_allで全部解放される. */

  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
