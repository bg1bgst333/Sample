/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */

/* main関数 */
int main(void){

  /* ポインタの宣言 */
  struct lconv *lc; /* lconv構造体へのポインタlc. */
  char *current; /* 現在のロケール文字列へのポインタcurrent. */
  char *monetary; /* 通貨の表示方法のロケール文字列へのポインタmonetary. */
  char *all; /* 全てのロケール文字列へのポインタall. */

  /* 現在のロケール情報を取得. */
  lc = localeconv(); /* localeconvで取得したポインタをlcに格納. */
  printf("lc->decimal_point = %s\n", lc->decimal_point); /* lc->decimal_pointを出力. */
  printf("lc->thousands_sep = %s\n", lc->thousands_sep); /* lc->thousands_sepを出力. */
  printf("lc->currency_symbol = %s\n", lc->currency_symbol); /* lc->currency_symbolを出力. */

  /* ロケール文字列を取得. */
  current = setlocale(LC_ALL, NULL); /* 全体のロケールのロケール文字列を取得. */
  printf("current = %s\n", current); /* currentを出力. */

  /* 改行 */
  printf("\n"); /* "\n"を出力. */

  /* 通貨だけ日本にする. */
  current = setlocale(LC_MONETARY, "Japanese"); /* LC_MONETARYと"Japanese"を指定. */
  printf("current = %s\n", current); /* currentを出力. */

  /* 現在のロケール情報を取得. */
  lc = localeconv(); /* localeconvで取得したポインタをlcに格納. */
  printf("lc->decimal_point = %s\n", lc->decimal_point); /* lc->decimal_pointを出力. */
  printf("lc->thousands_sep = %s\n", lc->thousands_sep); /* lc->thousands_sepを出力. */
  printf("lc->currency_symbol = %s\n", lc->currency_symbol); /* lc->currency_symbolを出力. */

  /* 通貨と全てのロケール文字列. */
  monetary = setlocale(LC_MONETARY, NULL); /* LC_MONETARYとNULLを指定. */
  all = setlocale(LC_ALL, NULL); /* LC_ALLとNULLを指定. */
  printf("monetary = %s\n", monetary); /* monetaryを出力. */
  printf("all = %s\n", all); /* allを出力. */

  /* 改行 */
  printf("\n"); /* "\n"を出力. */

  /* 文字化けするのでUTF-8を指定. */
  current = setlocale(LC_MONETARY, "ja_JP.UTF-8"); /* LC_MONETARYと"ja_JP.UTF-8"を指定. */
  printf("current = %s\n", current); /* currentを出力. */

  /* 現在のロケール情報を取得. */
  lc = localeconv(); /* localeconvで取得したポインタをlcに格納. */
  printf("lc->decimal_point = %s\n", lc->decimal_point); /* lc->decimal_pointを出力. */
  printf("lc->thousands_sep = %s\n", lc->thousands_sep); /* lc->thousands_sepを出力. */
  printf("lc->currency_symbol = %s\n", lc->currency_symbol); /* lc->currency_symbolを出力. */

  /* 通貨と全てのロケール文字列. */
  monetary = setlocale(LC_MONETARY, NULL); /* LC_MONETARYとNULLを指定. */
  all = setlocale(LC_ALL, NULL); /* LC_ALLとNULLを指定. */
  printf("monetary = %s\n", monetary); /* monetaryを出力. */
  printf("all = %s\n", all); /* allを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
