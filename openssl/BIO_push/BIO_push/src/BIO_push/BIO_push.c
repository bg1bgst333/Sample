/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <openssl/bio.h> /* BIO */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  BIO *buffer = NULL; /* バッファ用フィルタBIOへのポインタbufferをNULLに初期化. */
  BIO *file = NULL; /* ファイル用データシンクBIOへのポインタfileをNULLに初期化. */

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

  /* bufferとfileを連結. */
  BIO_push(buffer, file); /* BIO_pushでbufferとfileを連結. */

  /* bufferに"ABCDE"を書き込む. */
  BIO_write(buffer, "ABCDE", 5); /* BIO_writeでbufferに"ABCDE"を書き込む. */

  /* バッファをフラッシュしてファイルに書き込まれる. */
  BIO_flush(buffer); /* BIO_flushすることでbufferからfileにちゃんと書き込まれる. */

  /* BIOの解放. */
  BIO_free_all(buffer); /* bufferとfileは連結しているのでBIO_free_allで両方解放される. */

  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
