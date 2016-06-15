/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int func(int (*funcptr)(int), int x); /* 関数ポインタを引数に取る関数func. */
int func1(int i); /* 関数ポインタで参照する関数その1, func1. */
int func2(int i); /* 関数ポインタで参照する関数その2, func2. */

/* main関数の定義 */
int main(void){

  /* 変数, 関数ポインタの宣言. */
  int (*func_ptr)(int); /* intを引数に取り, intを戻り値に取る関数ポインタfunc_ptr. */
  int x; /* int型変数x. */
  int result; /* int型変数result. */

  /* 値の入力 */
  printf("x: "); /* xの入力フォーム */
  scanf("%d", &x); /* 入力された値をxに格納. */

  /* どちらの関数ポインタをセットするか判定. */
  if (x >= 0){ /* 0以上の時. */
    func_ptr = func1; /* func_ptrにfunc1のアドレスを格納. */
  }
  else{ /* 0より小さい時 */
    func_ptr = func2; /* func_ptrにfunc2のアドレスを格納. */
  }

  /* funcにfunc_ptrをセット. */
  result = func(func_ptr, x); /* funcの引数にfunc_ptrとxを渡す. */

  /* resultの出力 */
  printf("result = %d\n", result); /* printfでresultを出力. */

  /* プログラムの終了 */
  return 0;

}

/* 関数funcの定義. */
int func(int (*funcptr)(int), int x){

  /* funcptrを参照することで呼び出し. */
  return (*funcptr)(x); /* (*funcptr)にxを渡す. */

}

/* 関数func1の定義. */
int func1(int i){

  /* そのまま返す. */
  printf("func1!\n"); /* printfで"func1!"と出力. */
  return i; /* iを返す. */

}

/* 関数func2の定義. */
int func2(int i){

  /* -1を掛けて返す. */
  printf("func2!\n"); /* printfで"func2!"と出力. */
  return -1 * i; /* -1 * iを返す. */

}
