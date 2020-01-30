/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <setjmp.h> /* setjmp */

/* 関数のプロトタイプ宣言 */
void func(void); /* 関数func */

/* ジャンプバッファの宣言 */
jmp_buf env; /* 実行コンテキストを格納するjmp_buf型env */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int x; /* int型変数x. */

  /* 実行コンテキストの格納 */
  x = 10; /* xに10を代入. */
  if (setjmp(env) == 0){ /* setjmpでenvに実行コンテキストを格納.(セットの時は0が返る.) */

    /* xの値を変更. */
    x = 20; /* xに20を代入. */

    /* xの値を出力. */
    printf("x = %d\n", x); /* printfでxの値を出力. */

    /* funcを呼び出す. */
    func(); /* 関数func()を呼び出す.(中でlongjmpする.) */

  }
  else{ /* longjmpが呼ばれるとここに来る. */

    /* xの値を出力.(xの値は未定義なので本来は参照してはいけない.) */
    printf("x = %d\n", x); /* printfでxの値を出力. */

  }
  
  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* 関数func */
void func(void){

  /* longjmpを呼び出す. */
  longjmp(env, 1); /* setjmpの戻り値が1となって, setjmpの下のelseの場所に飛ぶ. */

}
