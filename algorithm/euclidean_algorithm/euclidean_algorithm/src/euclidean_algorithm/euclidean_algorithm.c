/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言. */
int euclidean_algorithm_1(int m, int n); /* ユークリッドの互除法(減算による方法). */
int euclidean_algorithm_2(int m, int n); /* ユークリッドの互除法(剰余による方法). */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int a; /* int型変数a */
  int b; /* int型変数b */
  int result1; /* int型変数result1 */
  int result2; /* int型変数result2 */

  /* 2つの整数を入力. */
  printf("a: "); /* aの入力フォーム. */
  scanf("%d", &a); /* 入力された値をaに格納. */
  printf("b: "); /* bの入力フォーム. */
  scanf("%d", &b); /* 入力された値をbに格納. */

  /* euclidean_algorithm_1で最大公約数を取得. */
  result1 = euclidean_algorithm_1(a, b); /* euclidean_algorithm_1にa, bを渡して, 結果をresult1に格納. */

  /* euclidean_algorithm_2で最大公約数を取得. */
  result2 = euclidean_algorithm_2(a, b); /* euclidean_algorithm_2にa, bを渡して, 結果をresult2に格納. */

  /* 結果の出力. */
  printf("result1 = %d\n", result1); /* result1を出力. */
  printf("result2 = %d\n", result2); /* result2を出力. */

  /* プログラムの終了. */
  return 0; /* 0を返して正常終了. */

}

/* ユークリッドの互除法(減算による方法). */
int euclidean_algorithm_1(int m, int n){

  /* 減算の繰り返しで最大公約数を求める. */
  while (m != n){ /* mとnが等しくなるまで繰り返す. */
    if (m > n){ /* mがnより大きい時. */
      m = m - n; /* m - nの結果をmに格納. */
    }
    else{ /* mがn以下の時. */
      n = n - m; /* n - mの結果をnに格納. */
    }
  }

  /* 最後にmを返す(mとnは等しく, 最大公約数.) */
  return m; /* returnでmを返す. */

}

/* ユークリッドの互除法(剰余による方法). */
int euclidean_algorithm_2(int m, int n){

  /* 変数の宣言 */
  int p; /* int型変数p. */
  int q; /* int型変数q. */
  int r; /* int型変数r. */

  /* 剰余の繰り返しで最大公約数を求める. */
  if (m > n){ /* mがnより大きい時. */
    p = m; /* pにmを格納. */
    q = n; /* qにnを格納. */
  }
  else{ /* mがn以下の時. */
    p = n; /* pにnを格納. */
    q = m; /* qにmを格納. */
  }
  do{
    r = p % q; /* pをqで割った余り(剰余)をrに格納. */
    p = q; /* qをpに格納. */
    q = r; /* rをqに格納. */
  } while (r != 0); /* rが0になるまで繰り返す. */

  /* 最後にpを返す. */
  return p; /* returnでpを返す. */

}
