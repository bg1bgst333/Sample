/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数 */
int main(void){

  /* 変数の宣言と初期化. */
  FILE *fp; /* ファイルポインタfp */
  char buf[256] = {0}; /* バッファbuf(長さ256)を{0}で初期化. */
  size_t read_len = 0; /* 読み込めた長さread_lenを0で初期化. */

  /* test.txtをバイナリ読み込みで開く. */
  fp = fopen("test.txt", "rb"); /* fopenで"test.txt"を"rb"で開き, ファイルポインタをfpに格納. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    perror("test.txt"); /* perrorで"test.txt"に関するエラーを出力. */
    return -1; /* -1を返して異常終了. */

  }

  /* 読み込みループ */
  while (1){ /* 無限ループ */

    /* 3バイトずつ読み込む. */
    memset(buf, '\0', 256); /* memsetでbufをクリア. */
    read_len = fread(buf, 1, 3, fp); /* freadで3バイト読み込み, 読み込んだ長さをread_lenに格納. */
    printf("buf = [%s], read_len = %d\n", buf, (int)read_len); /* bufとread_lenを出力. */
    perror("fread"); /* perrorで"fread"がエラーなのか出力してみる. */
    if (read_len < 3){ /* 3よりも小さい時. */
      if (feof(fp)){ /* feofでEOFかどうかをチェック. */
        printf("feof(fp): true\n"); /* EOFである. */ 
      }
      else{
        printf("feof(fp): false\n"); /* EOFではない. */
      }
      break; /* とりあえずループを抜ける. */
    }

  }

  /* "test.txt"を閉じる. */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
