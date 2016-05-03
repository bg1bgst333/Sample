/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int a; /* int型変数a */
  char ch_a[8 + 1]; /* aの2進数文字列ch_a */
  int b; /* int型変数b */
  char ch_b[8 + 1]; /* bの2進数文字列ch_b */
  int t; /* 一時変数t */
  int i; /* ループ用変数i */
  int x; /* int型変数x */
  char ch_x[8 + 1]; /* xの2進数文字列ch_x */
  int y; /* int型変数y */
  char ch_y[8 + 1]; /* yの2進数文字列ch_y */
  unsigned int nx; /* unsigned int型変数nx */
  unsigned int ut; /* unsigned int用一時変数ut */
  char ch_nx[32 + 1]; /* nxの2進数文字列ch_nx */
  int xab; /* int型変数xab */
  char ch_xab[8 + 1]; /* xabの2進数文字列ch_xab */
  int rx; /* int型変数rx */
  char ch_rx[8 + 1]; /* rxの2進数文字列ch_rx */
  int lx; /* int型変数lx */
  char ch_lx[8 + 1]; /* lxの2進数文字列ch_lx */

  /* aの入力 */
  printf("a: "); /* aの入力フォーム */
  scanf("%d", &a); /* 入力された整数値をaに格納. */

  /* bの入力 */
  printf("b: "); /* bの入力フォーム */
  scanf("%d", &b); /* 入力された整数値をbに格納. */

  /* aの出力 */
  t = a; /* tにaを代入. */
  printf("a(2) = "); /* aの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_a[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_a[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_a[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_a); /* ch_aを出力. */

  /* bの出力 */
  t = b; /* tにbを代入. */
  printf("b(2) = "); /* bの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_b[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_b[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_b[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_b); /* ch_bを出力. */

  /* ビット演算OR */
  x = a | b; /* aとbのビット演算OR */
  t = x; /* tにxを代入. */
  printf("x(2) = "); /* xの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_x[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_x[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_x[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_x); /* ch_xを出力. */

  /* ビット演算AND */
  y = a & b; /* aとbのビット演算AND */
  t = y; /* tにyを代入. */
  printf("y(2) = "); /* yの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_y[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_y[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_y[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_y); /* ch_yを出力. */

  /* ビット演算NOT */
  nx = (unsigned int)~x; /* xのビット演算NOT((unsigned int)でキャスト.) */
  ut = nx; /* utにnxを代入. */
  printf("nx(2) = "); /* nxの2進数の値 */
  for (i = 31; i >= 0; i--){ /* 31から0まで繰り返す. */
    ch_nx[i] = '0' + ut % 2; /* utを2で割った余りを'0'に足したものをch_nx[i]に格納. */
    ut = ut / 2; /* utを2で割った値をutに格納. */
  }
  ch_nx[32] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_nx); /* ch_nxを出力. */

  /* ビット演算XOR */
  xab = a ^ b; /* aとbのビット演算XOR */
  t = xab; /* tにxabを代入. */
  printf("xab(2) = "); /* xabの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_xab[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_xab[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_xab[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_xab); /* ch_xabを出力. */

  /* ビット演算RSHIFT */
  rx = x >> 2; /* xのビット演算RSHIFT(今回は右に2つシフト.) */
  t = rx; /* tにrxを代入. */
  printf("rx(2) = "); /* rxの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_rx[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_rx[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_rx[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_rx); /* ch_rxを出力. */

  /* ビット演算LSHIFT */
  lx = x << 2; /* xのビット演算LSHIFT(今回は左に2つシフト.) */
  t = lx; /* tにlxを代入. */
  printf("lx(2) = "); /* lxの2進数の値 */
  for (i = 7; i >= 0; i--){ /* 7から0まで繰り返す. */
    ch_lx[i] = '0' + t % 2; /* tを2で割った余りを'0'に足したものをch_lx[i]に格納. */
    t = t / 2; /* tを2で割った値をtに格納. */
  }
  ch_lx[8] = '\0'; /* 最後はNULL文字. */
  printf("%s\n", ch_lx); /* ch_lxを出力. */

  /* プログラムの終了 */
  return 0;

}
