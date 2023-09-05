/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <wchar.h> /* ワイド文字 */
#include <locale.h> /* ロケール */
#include <limits.h> /* 限界値 */
#include <sys/stat.h> /* ファイル状態 */

/* main関数の定義 */
int main(void){

  /* ロケールのセット("ja_JP.UTF-8") */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* 構造体の宣言 */
  struct stat sst1; /* stat構造体変数sst1. */

  /* ファイル情報を取得. */
  if (stat("test1.txt", &sst1) != 0){ /* statで"test1.txt"のファイル情報を取得し, sst1に格納.(0以外は失敗.) */
    perror("stat test1");
    return -1;
  }

  /* バイナリファイル入力 */
  FILE *fp1 = fopen("test1.txt", "rb"); /* "test1.txt"を開く. */
  if (fp1 == NULL){ /* 失敗 */
    perror("open test1");
    return -2;
  }
  char *mb1_ptr = malloc((sst1.st_size + 1) * sizeof(char)); /* mallocで(sst1.st_size + 1) * sizeof(char)分のメモリ確保し, ポインタはmb1_ptrに格納. */
  fread(mb1_ptr, sizeof(char), sst1.st_size, fp1); /* freadで読み込み, mb1_ptrに格納. */
  *(mb1_ptr + sst1.st_size) = '\0'; /* 末尾にNULL文字. */
  printf("mb1_ptr = %s\n", mb1_ptr); /* mb1_ptrを出力. */

  /* マルチバイト文字からワイド文字に変換. */
  wchar_t wc1; /* wchar_t型変数wc1. */
  int result1 = mbtowc(&wc1, mb1_ptr, MB_CUR_MAX); /* mbtowcでワイド文字に変換. */
  if (result1 < 0){ /* マイナスは失敗. */
    perror("mbtowc test1");
    free(mb1_ptr); /* mb1_ptr解放 */
    fclose(fp1); /* fp1を閉じる. */
    return -3;
  }
  printf("wc1 = %lc\n", wc1); /* printfでwc1を出力. */

  /* 終了処理 */
  free(mb1_ptr); /* mb1_ptr解放 */
  fclose(fp1); /* fp1を閉じる. */

  /* ロケールのセット("ja_JP.EUC-JP") */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* 構造体の宣言 */
  struct stat sst2; /* stat構造体変数sst2. */

  /* ファイル情報を取得. */
  if (stat("test2.txt", &sst2) != 0){ /* statで"test2.txt"のファイル情報を取得し, sst2に格納.(0以外は失敗.) */
    perror("stat test2");
    return -4;
  }

  /* バイナリファイル入力 */
  FILE *fp2 = fopen("test2.txt", "rb"); /* "test2.txt"を開く. */
  if (fp2 == NULL){ /* 失敗 */
    perror("open test2");
    return -5;
  }
  char *mb2_ptr = malloc((sst2.st_size + 1) * sizeof(char)); /* mallocで(sst2.st_size + 1) * sizeof(char)分のメモリ確保し, ポインタはmb2_ptrに格納. */
  fread(mb2_ptr, sizeof(char), sst2.st_size, fp2); /* freadで読み込み, mb2_ptrに格納. */
  *(mb2_ptr + sst2.st_size) = '\0'; /* 末尾にNULL文字. */
  printf("mb2_ptr = %s\n", mb2_ptr); /* mb2_ptrを出力. */

  /* マルチバイト文字からワイド文字に変換. */
  wchar_t wc2; /* wchar_t型変数wc2. */
  int result2 = mbtowc(&wc2, mb2_ptr, MB_CUR_MAX); /* mbtowcでワイド文字に変換. */
  if (result2 < 0){ /* マイナスは失敗. */
    perror("mbtowc test2");
    free(mb2_ptr); /* mb2_ptr解放 */
    fclose(fp2); /* fp2を閉じる. */
    return -6;
  }
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.(下でwc2を表示するのにも"ja_JP.UTF-8"にしないといけない.) */
  printf("wc2 = %lc\n", wc2); /* printfでwc2を出力. */

  /* 終了処理 */
  free(mb2_ptr); /* mb2_ptr解放 */
  fclose(fp2); /* fp2を閉じる. */

  /* 正常終了 */
  return 0; /* 0を返して正常終了. */

}
