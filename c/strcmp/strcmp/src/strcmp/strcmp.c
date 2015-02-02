/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 配列の宣言 */
  char str1[256]; /* 入力された文字列を格納するchar型配列str1. */
  char str2[] = "ABCDE"; /* 比較対象となるchar型配列str2は"ABCDE"と初期化. */
  int compare_result; /* strcmpによる比較の結果を格納するint型変数compare_result. */

  /* 文字列の入力 */
  printf("str1: "); /* str1の入力フォーム */
  scanf("%s", str1); /* 入力された文字列をstr1に格納. */

  /* 文字列の比較 */
  compare_result = strcmp(str1, str2); /* strcmpでstr1とstr2を比較. */
  if (compare_result < 0){ /* str1とstr2の要素である文字を先頭から比較して, 違う文字となったところで, ASCIIコードがstr1の比較対象文字の方が小さい場合.(str1, str2の文字列長の短い方の最後の文字まで同じだった場合は, str1が文字列長が短い場合.) */
  
    /* ASCII順でstr1の方が先. */
    printf("str1(\"%s\") < str2(\"%s\")\n", str1, str2); /* str1 < str2であることを出力. */

  }
  else if (compare_result > 0){ /* str2の比較対象文字の方が小さい場合.(短い方の最後まで同じ場合は, str2が短い場合.) */

    /* ASCII順でstr2の方が先. */
    printf("str1(\"%s\") > str2(\"%s\")\n", str1, str2); /* str1 > str2であることを出力. */

  }
  else{ /* str1とstr2が等しい場合 */

    /* 同じ文字列 */
    printf("str1(\"%s\") == str2(\"%s\")\n", str1, str2); /* str1 == str2であることを出力. */

  }

  /* プログラムの終了 */
  return 0;

}
