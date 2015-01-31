/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言 */
  char name[32]; /* test.txtに書き込む名前を格納するchar型配列name. */
  int age; /* test.txtに書き込む年齢を格納するint型変数age. */
  char address[128]; /* test.txtに書き込む住所を格納するchar型配列address. */
  FILE *fp; /* ファイルポインタfp */

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "w"); /* fopenで"test.txt"というファイルを書込専用("w")で開く. */
  if (fp == NULL){ /* fp == NULLならファイルを開くのに失敗.(ファイルが存在しない場合は新規作成されるので, 失敗することはあまりない.) */

    /* エラー処理 */
    printf("Can't open file!\n"); /* ファイルが開けない場合のエラーメッセージ. */
    return -1; /* 異常終了 */

  }

  /* 書き込む名前の入力. */
  printf("name: "); /* nameの入力フォーム */
  scanf("%s", name); /* 入力された名前をnameに格納. */

  /* 書き込む年齢の入力. */
  printf("age: "); /* ageの入力フォーム */
  scanf("%d", &age); /* 入力された年齢をageに格納. */

  /* 書き込む住所の入力. */
  printf("address: "); /* addressの入力フォーム */
  scanf("%s", address); /* 入力された住所をaddressに格納. */

  /* ファイルへの書き込み */
  fprintf(fp, "%s %d %s", name, age, address); /* fprintfで"test.txt"にname, age, addressを指定書式で書き込む. */

  /* 書き込み完了メッセージ */
  printf("Completed.\n"); /* "Completed."と出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで"test.txt"を閉じる. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
