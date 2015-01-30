/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言 */
  int x; /* test.txtに書き込む整数値を格納するint型変数x. */
  char str[256]; /* test.txtに書き込む文字列を格納するchar型配列str. */

  FILE *fp; /* ファイルポインタfp */

  /* ファイルtest.txtを開く. */
  fp = fopen("test.txt", "w"); /* fopenで"test.txt"というファイルを書込専用("w")で開く. */
  if (fp == NULL){ /* fp == NULLならファイルを開くのに失敗.(ファイルが存在しない場合は新規作成されるので, 失敗することはあまりない.) */

    /* エラー処理 */
    printf("Can't open file!\n"); /* ファイルが開けない場合のエラーメッセージ. */
    return -1; /* 異常終了 */

  }

  /* 書き込む整数値の入力. */
  printf("x: "); /* xの入力フォーム */
  scanf("%d", &x); /* 入力された整数値をxに格納. */

  /* 書き込む文字列の入力. */
  printf("str: "); /* strの入力フォーム */
  scanf("%s", str); /* 入力された文字列をstrに格納. */

  /* ファイルへの書き込み */
  fprintf(fp, "x: %d\nstr: %s", x, str); /* fprintfで"test.txt"にxとstrを指定書式で書き込む. */

  /* 書き込み完了メッセージ */
  printf("Completed.\n"); /* "Completed."と出力. */

  /* ファイルを閉じる. */
  fclose(fp); /* fcloseで"test.txt"を閉じる. */

  /* プログラムの終了 */
  return 0; /* 正常終了 */

}
