/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void print_inner_str(void); /* 関数print_inner_str()のプロトタイプ宣言 */
void print_add_result(int x, int y); /* 関数print_add_result()のプロトタイプ宣言 */
int get_add_result(int x, int y); /* 関数get_add_result()のプロトタイプ宣言 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int x; /* int型変数x */
  int y; /* int型変数y */
  int add_result; /* get_add_resultの戻り値を格納するint型変数add_result. */

  /* x, yの入力 */
  printf("x: "); /* xの入力フォーム */
  scanf("%d", &x); /* 入力された整数値をxに格納. */
  printf("y: "); /* yの入力フォーム */
  scanf("%d", &y); /* 入力された整数値をyに格納. */

  /* 引数も戻り値も無い関数の呼び出し. */
  print_inner_str(); /* 関数print_inner_str()を呼ぶ. */

  /* 引数のある関数の呼び出し. */
  print_add_result(x, y); /* 関数print_add_result()を呼び, 引数にx, yを渡す. */

  /* 引数も戻り値もある関数の呼び出し. */
  add_result = get_add_result(x, y); /* 関数get_add_result()を呼び, 引数にx, yを渡し, 戻り値をadd_resultに格納する. */
  printf("get_add_result's add_result = %d\n", add_result); /* add_resultを出力. */

  /* プログラムの終了 */
  return 0;

}

/* 関数printf_inner_str()の定義 */
void print_inner_str(void){ /* 内部文字列を標準出力する.(引数無し, 戻り値無し) */

  /* 内部文字列の出力 */
  printf("print_inner_str\n"); /* printfで内部文字列"print_inner_str"を出力. */

}

/* 関数print_add_result()の定義 */
void print_add_result(int x, int y){ /* 引数として渡されたxとyを足して, その結果を標準出力する.(引数x, y, 戻り値無し) */

  /* 変数の宣言 */
  int add_result; /* xとyを足した結果を格納するint型ローカル変数add_result. */

  /* xとyの加算 */
  add_result = x + y; /* xとyを足して, 結果をadd_resultに格納. */

  /* 結果の出力 */
  printf("print_add_result's add_result = %d\n", add_result); /* ローカル変数add_resultを出力. */

}

/* 関数get_add_result()の定義 */
int get_add_result(int x, int y){ /* 引数として渡されたxとyを足して, その結果の値を戻り値として返す.(引数x, y, 戻り値の型はint) */

  /* 計算結果を返す. */
  return x + y; /* return文でx + yの値を戻り値として返す. */

}
