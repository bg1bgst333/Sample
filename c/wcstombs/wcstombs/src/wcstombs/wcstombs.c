/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <wchar.h> /* ワイド文字 */
#include <locale.h> /* ロケール */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  wchar_t wstr[] = L"あいうえお"; /* wchar_t型配列wstrをL"あいうえお"で初期化. */

  /* ロケールのセット("ja_JP.UTF-8") */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* 標準出力 */
  printf("wstr = %ls\n", wstr); /* wstrを出力. */

  /* バッファサイズ取得. */
  int buf_size1 = wcstombs(NULL, wstr, -1); /* 先頭NULLで必要バッファサイズをbuf_size1に格納. */

  /* ワイド文字列からマルチバイト文字列(UTF-8)へ変換. */
  char *mb1_ptr = malloc((buf_size1 + 1) * sizeof(char)); /* (buf_size1 + 1)分のメモリ確保. */
  int len1 = wcstombs(mb1_ptr, wstr, buf_size1); /* wcstombsで変換. */
  *(mb1_ptr + len1) = '\0'; /* 終端はNULL. */

  /* 標準出力 */
  printf("mb1_ptr = %s\n", mb1_ptr); /* mb1_ptrを出力. */
  printf("len1 = %d\n", len1); /* len1を出力. */

  /* バイナリファイル出力 */
  FILE *fp1 = fopen("test1.txt", "wb"); /* "test1.txt"を開く. */
  if (fp1 == NULL){ /* 失敗 */
    perror("test1");
    free(mb1_ptr); /* 解放 */
    return -1;
  }
  fwrite(mb1_ptr, sizeof(char), len1, fp1); /* fwriteでmb1_ptrを書き込む. */
  fclose(fp1); /* 閉じる */
  free(mb1_ptr); /* 解放 */

  /* ロケールのセット("ja_JP.EUC-JP") */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* バッファサイズ取得. */
  int buf_size2 = wcstombs(NULL, wstr, -1); /* 先頭NULLで必要バッファサイズをbuf_size2に格納. */

  /* ワイド文字列からマルチバイト文字列(EUC-JP)へ変換. */
  char *mb2_ptr = malloc((buf_size2 + 1) * sizeof(char)); /* (buf_size2 + 1)分のメモリ確保. */
  int len2 = wcstombs(mb2_ptr, wstr, buf_size2); /* wcstombsで変換. */
  *(mb2_ptr + len2) = '\0'; /* 終端はNULL. */

  /* 標準出力 */
  printf("mb2_ptr = %s\n", mb2_ptr); /* mb2_ptrを出力. */
  printf("len2 = %d\n", len2); /* len2を出力. */

  /* バイナリファイル出力 */
  FILE *fp2 = fopen("test2.txt", "wb"); /* "test2.txt"を開く. */
  if (fp2 == NULL){ /* 失敗 */
    perror("test2");
    free(mb2_ptr); /* 解放 */
    return -2;
  }
  fwrite(mb2_ptr, sizeof(char), len2, fp2); /* fwriteでmb2_ptrを書き込む. */
  fclose(fp2); /* 閉じる */
  free(mb2_ptr); /* 解放 */

  /* 正常終了 */
  return 0; /* 0を返して正常終了. */

}
