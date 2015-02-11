/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 変数・ポインタの宣言 */
  int age; /* prof.binから読み出した年齢. */
  FILE *fp; /* ファイルポインタfp */

  /* prof.binのバイナリ読み込み. */
  fp = fopen("prof.bin", "rb"); /* prof.binをバイナリ読み込み("rb")で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* ファイルのアクセス位置の変更. */
  fseek(fp, 32, SEEK_SET); /* fseekで, prof.binの中のデータ構造struct_tag_profileのnameのサイズ(32バイト)分アクセス位置を飛ばす. */

  /* prof.binのageの部分だけ読み込む. */
  fread((void *)&age, sizeof(age), 1, fp); /* freadでprof.binのstruct_tag_profileにおけるageの部分だけ読み込む. */

  /* ageの出力. */
  printf("age: %d\n", age); /* printfで読み出したageを出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで閉じる. */

  /* プログラムの終了 */
  return 0;

}
