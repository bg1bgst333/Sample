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
  struct struct_tag_profile prof; /* struct_tag_profile型構造体変数prof */
  FILE *fp; /* ファイルポインタfp */

  /* profへの入力. */
  printf("prof.name: "); /* prof.nameの入力フォーム */
  scanf("%s", prof.name); /* 入力された名前をprof.nameに格納. */
  printf("prof.age: "); /* prof.ageの入力フォーム */
  scanf("%d", &prof.age); /* 入力された年齢をprof.ageに格納. */
  printf("prof.address: "); /* prof.addressの入力フォーム */
  scanf("%s", &prof.address); /* 入力された住所をprof.addressに格納. */

  /* この構造体をprof.binにバイナリ書き込みする. */
  fp = fopen("prof.bin", "wb"); /* prof.binをバイナリ書き込み("wb")で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* profをファイルに書き込む. */
  fwrite((void *)&prof, sizeof(prof), 1, fp); /* fwriteでprofをprof.binにバイナリ書き込み. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで閉じる. */

  /* プログラムの終了 */
  return 0;

}
