/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <wchar.h> /* ワイド文字 */
#include <locale.h> /* ロケール */
#include <limits.h> /* 限界値 */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  const wchar_t wc = L'あ'; /* wchar_t型定数wcをL'あ'で初期化. */

  /* ロケールのセット("ja_JP.UTF-8") */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* wchar_t型変数のサイズ. */
  int wcsize = sizeof(wc); /* sizeofでwcのサイズを計測し, wcsizeに格納. */

  /* 標準出力 */
  printf("wc = %lc\n", wc); /* wcを出力. */
  printf("wc(%%08x) = 0x%08x\n", wc); /* wcを16進数出力. */
  printf("wcsize = %d\n", wcsize); /* wcsizeを出力. */

  /* ワイド文字からマルチバイト文字(UTF-8)へ変換. */
  char mb1[MB_LEN_MAX + 1] = {0}; /* char型配列mb1(長さMB_LEN_MAX + 1)を{0}で初期化. */
  int len1 = wctomb(mb1, wc); /* wctombでワイド文字からマルチバイト文字へ変換. */

  /* 標準出力 */
  printf("mb1 = %s\n", mb1); /* mb1を出力. */
  printf("len1 = %d\n", len1); /* len1を出力. */

  /* バイナリファイル出力 */
  FILE *fp1 = fopen("test1.txt", "wb"); /* "test1.txt"を開く. */
  if (fp1 == NULL){ /* 失敗 */
    perror("test1");
    return -1;
  }
  fwrite(mb1, sizeof(char), len1, fp1); /* fwriteでmb1を書き込む. */
  fclose(fp1); /* 閉じる */

  /* ロケールのセット("ja_JP.EUC-JP") */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* ワイド文字からマルチバイト文字(EUC-JP)へ変換. */
  char mb2[MB_LEN_MAX + 1] = {0}; /* char型配列mb2(長さMB_LEN_MAX + 1)を{0}で初期化. */
  int len2 = wctomb(mb2, wc); /* wctombでワイド文字からマルチバイト文字へ変換. */

  /* 標準出力 */
  printf("mb2 = %s\n", mb2); /* mb2を出力. */
  printf("len2 = %d\n", len2); /* len2を出力. */

  /* バイナリファイル出力 */
  FILE *fp2 = fopen("test2.txt", "wb"); /* "test2.txt"を開く. */
  if (fp2 == NULL){ /* 失敗 */
    perror("test2");
    return -2;
  }
  fwrite(mb2, sizeof(char), len2, fp2); /* fwriteでmb2を書き込む. */
  fclose(fp2); /* 閉じる */

  /* 正常終了 */
  return 0; /* 0を返して正常終了. */

}
