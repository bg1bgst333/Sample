/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 配列・変数・ポインタの宣言 */
  char name[32]; /* prof.binから読み出した名前. */
  int age; /* prof.binから読み出した年齢. */
  char address[128]; /* prof.binから読み出した住所. */
  FILE *fp; /* ファイルポインタfp */
  long position; /* ファイルアクセス位置 */

  /* prof.binのバイナリ読み込み. */
  fp = fopen("prof.bin", "rb"); /* prof.binをバイナリ読み込み("rb")で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* この時点でのファイルアクセス位置を取得. */
  position = ftell(fp); /* ftellでアクセス位置を取得. */
  printf("position: %ld\n", position); /* positionを出力. */

  /* prof.binのnameの部分だけ読み込む. */
  fread((void *)name, sizeof(char), 32, fp); /* freadでprof.binのstruct_tag_profileにおけるnameの部分だけ読み込む. */
  printf("name: %s\n", name); /* nameを出力. */

  /* この時点でのファイルアクセス位置を取得. */
  position = ftell(fp); /* ftellでアクセス位置を取得. */
  printf("position: %ld\n", position); /* positionを出力. */

  /* prof.binのageの部分だけ読み込む. */
  fread((void *)&age, sizeof(age), 1, fp); /* freadでprof.binのstruct_tag_profileにおけるageの部分だけ読み込む. */
  printf("age: %d\n", age); /* ageを出力. */

  /* この時点でのファイルアクセス位置を取得. */
  position = ftell(fp); /* ftellでアクセス位置を取得. */
  printf("position: %ld\n", position); /* positionを出力. */

  /* prof.binのaddressの部分だけ読み込む. */
  fread((void *)address, sizeof(char), 128, fp); /* freadでprof.binのstruct_tag_profileにおけるaddressの部分だけ読み込む. */
  printf("address: %s\n", address); /* addressを出力. */

  /* この時点でのファイルアクセス位置を取得. */
  position = ftell(fp); /* ftellでアクセス位置を取得. */
  printf("position: %ld\n", position); /* positionを出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで閉じる. */

  /* プログラムの終了 */
  return 0;

}
