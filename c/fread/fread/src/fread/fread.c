/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* 構造体タグstruct_tag_profileの定義 */
struct struct_tag_profile{ /* 簡易名簿 */
  char name[32]; /* 名前 */
  int age; /* 年齢 */
  char address[128]; /* 住所 */
};

/* main関数の定義 */
int main(void){

  /* 構造体変数・ポインタの宣言 */
  struct struct_tag_profile prof; /* struct_tag_profile型構造体変数prof. */
  FILE *fp; /* ファイルポインタfp */

  /* prof.binをバイナリ読み込みする. */
  fp = fopen("prof.bin", "rb"); /* prof.binをバイナリ読み込み("rb")で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* prof.binを読み込んで, profに格納. */
  fread((void *)&prof, sizeof(prof), 1, fp); /* freadでprof.binをバイナリ読み込みし, profに格納. */

  /* profの内容を出力. */
  printf("prof.name = %s\n", prof.name); /* prof.nameを出力. */
  printf("prof.age = %d\n", prof.age); /* prof.ageを出力. */
  printf("prof.address = %s\n", prof.address); /* prof.addressを出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで閉じる. */

  /* プログラムの終了 */
  return 0;

}
