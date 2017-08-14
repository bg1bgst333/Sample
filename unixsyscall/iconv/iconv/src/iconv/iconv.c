/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <iconv.h> /* 文字コード変換 */

/* main関数 */
int main(void){

  /* 変数の宣言と初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  char buf[256] = {0}; /* char型バッファbufを0で初期化.(長さ256) */
  char *buf_ptr; /* bufのアドレスを持つポインタbuf_ptr. */
  size_t len; /* bufの長さlen. */
  iconv_t iconv_dsc; /* 変換ディスクリプタiconv_dsc. */
  char buf2[256] = {0}; /* char型バッファbuf2を0で初期化.(長さ256) */
  size_t len2; /* buf2の大きさlen2. */
  char *buf2_ptr; /* buf2のアドレスを持つポインタbuf2_ptr. */
  size_t ret_len; /* iconvの戻り値ret_len. */

  /* test1.txtの読み込み. */
  fp = fopen("test1.txt", "r"); /* fopenで"test1.txt"を開く. */
  if (fp == NULL){ /* NULLなら. */
    printf("fopen error!\n"); /* "fopen error!"を出力. */
    return -1; /* -1を返して異常終了. */
  }
  fgets(buf, 256, fp); /* fgetsで読み込んでbufに格納. */
  len = strlen(buf); /* strlenでbufの長さを取得. */
  if (buf[len - 1] == '\n'){ /* buf[len - 1]が改行なら. */
    buf[len - 1] = '\0'; /* buf[len - 1]をNULL文字('\0')にする. */
  }
  fclose(fp); /* fcloseでfpを閉じる. */

  /* 変換ディスクリプタの取得. */
  iconv_dsc = iconv_open("utf-8", "Shift_JIS"); /* iconv_openで"utf-8"から"Shift_JIS"への変換ディスクリプタを取得. */
  if (iconv_dsc == (iconv_t)-1){ /* -1なら. */
    printf("iconv_open error!\n"); /* "iconv_open error!"を出力.
    return -2; /* -2を返して異常終了. */
  }

  /* 文字コード変換. */
  buf_ptr = buf; /* bufのアドレスをbuf_ptrに渡す. */
  len = strlen(buf); /* bufの長さをlenに格納. */
  len2 = sizeof(buf2); /* buf2の大きさをlen2に格納. */
  buf2_ptr = buf2; /* buf2のアドレスをbuf2_ptrに渡す. */
  ret_len = iconv(iconv_dsc, &buf_ptr, &len, &buf2_ptr, &len2); /* iconvで変換. */
  if (ret_len == -1){ /* -1なら. */
    printf("iconv error!\n"); /* "iconv error!"と出力. */
    perror("iconv error detail"); /* エラー詳細. */
    return -3; /* -3を返して異常終了. */
  }

  /* 変換ディスクリプタを閉じる. */
  iconv_close(iconv_dsc); /* iconv_closeでiconv_dscを閉じる. */

  /* test2.txtの書き込み. */
  fp = fopen("test2.txt", "w"); /* fopenで"test2.txt"を開く. */
  fputs(buf2, fp); /* fputsでbuf2をfpに書き込み. */
  fclose(fp); /* fpを閉じる. */  

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
