/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdarg.h> /* 可変引数 */

/* 可変引数な関数のプロトタイプ宣言. */
int sum(int count, ...); /* 第2引数以降の数を全て足し合わせる関数sum. */
 
/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int result3; /* 3つの足し算の結果を格納するint型変数result3. */
  int result5; /* 5つの足し算の結果を格納するint型変数result5. */

  /* 1から3まで足し合わせる. */
  result3 = sum(3, 1, 2, 3); /* sumで1から3まで足し合わせる. */

  /* 1から5まで足し合わせる. */
  result5 = sum(5, 1, 2, 3, 4, 5); /* sumで1から5まで足し合わせる. */

  /* 結果の出力 */
  printf("result3 = %d\n", result3); /* printfでresult3を出力. */
  printf("result5 = %d\n", result5); /* printfでresult5を出力. */

  /* プログラムの終了 */
  return 0;
  
}

/* 関数sumの定義. */
int sum(int count, ...){ /* 第1引数はそれ以外の引数の個数. */

  /* 変数の宣言・初期化. */
  va_list args; /* 可変引数情報を持つva_list型変数args. */
  int i; /* ループ用int型変数i. */
  int x = 0; /* 引数の和を表すint型変数xを0に初期化. */

  /* 可変引数情報の取得. */
  va_start(args, count); /* va_startで可変引数情報を取得. */

  /* 引数を足し合わせる. */
  for (i = 0; i < count; i++){ /* count分繰り返す. */
    x = x + va_arg(args, int); /* va_argで各引数の値を取得しxに足す. */
  }

  /* 可変引数処理の終了. */
  va_end(args); /* va_endで引数処理の終了. */

  /* 結果を返す. */
  return x; /* xを返す. */

}
