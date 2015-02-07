/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力(ファイル入出力も含む.) */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 変数・配列・ポインタの宣言 */
  int len; /* filenameの長さ */
  char filename[256]; /* ファイル名(最大255( = 256 - 1)文字) */
  char text[256]; /* filenameで指定されたファイルに書き込む文字列(最大255( = 256 - 1)文字). */
  FILE *fp; /* ファイルポインタfp */

  /* ファイル名の入力. */
  printf("filename: "); /* filenameの入力フォーム */
  fgets(filename, 256, stdin); /* fgetsで標準入力(stdin)で入力されたファイル名をfilenameに格納. */

  /* 改行コードの除去 */
  len = strlen(filename); /* strlenでfilenameの長さを取得. */
  if (filename[len - 1] == '\n'){ /* 最後の文字が'\n'の場合. */
    filename[len - 1] = '\0'; /* '\n'を'\0'に置き換える. */
  }

  /* filenameで指定されたファイルを開く. */
  fp = fopen(filename, "w"); /* filenameを"w"で開く. */
  if (fp == NULL){ /* エラー */

    /* エラー処理 */
    printf("Can't open file!\n");
    return -1;

  }

  /* 書き込む文字列の入力. */
  printf("text: "); /* textの入力フォーム */
  fgets(text, 256, stdin); /* fgetsで標準入力(stdin)で入力された書き込む文字列をtextに格納. */
  
  /* 改行コードの除去 */
  len = strlen(text); /* strlenでtextの長さを取得. */
  if (text[len - 1] == '\n'){ /* 最後の文字が'\n'の場合. */
    text[len - 1] = '\0'; /* '\n'を'\0'に置き換える. */
  }

  /* filenameにtextを書き込む. */
  fputs(text, fp); /* fputsでfilenameにtextを書き込む. */

  /* filenameを閉じる. */
  fclose(fp); /* fcloseでfilenameを閉じる. */

  /* プログラムの終了 */
  return 0;

}
