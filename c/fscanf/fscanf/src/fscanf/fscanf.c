/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言 */
  char name[32]; /* test.txtから読み込んだ名前を格納するchar型配列name. */
  int age; /* test.txtから読み込んだ年齢を格納するint型変数age. */
  char address[128]; /* test.txtから読み込んだ住所を格納するchar型配列address. */
  FILE *fp; /* ファイルポインタfp */

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "r"); /* fopenで"test.txt"というファイルを読込専用("r")で開く. */  if (fp == NULL){ /* fp == NULLならファイルを開くのに失敗. */

    /* エラー処理 */
    printf("Can't open file!\n"); /* ファイルが開けない場合のエラーメッセージ. */
    return -1; /* 異常終了 */

  }

  /* ファイルからの読み込み */
  fscanf(fp, "%s %d %s", name, &age, address); /* fscanfで"test.txt"から読み込んだ内容をname, age, addressに格納する. */

  /* 読み込んだname, age, addressの出力 */
  printf("name: %s\n", name); /* printfでnameを出力. */
  printf("age: %d\n", age); /* printfでageを出力. */
  printf("address: %s\n", address); /* printfでaddressを出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで"test.txt"を閉じる. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
