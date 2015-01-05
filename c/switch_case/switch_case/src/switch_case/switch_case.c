/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の定義 */
  int a; /* int型変数a */
  int b; /* int型変数b */
  char op; /* 入力された演算子記号文字を格納するchar型変数op. */
  int result; /* 結果を格納するint型変数result. */

  /* aの入力 */
  printf("a: "); /* aの入力フォーム */
  scanf("%d", &a); /* 入力された整数値をaに格納. */

  /* opの入力 */
  printf("op: "); /* opの入力フォーム */
  scanf("%*c%c", &op); /* 入力された演算子記号文字をopに格納. */

  /* bの入力 */
  printf("b: "); /* bの入力フォーム */
  scanf("%d", &b); /* 入力された整数値をbに格納. */

  /* opごとに処理を分岐(switch-case文). */
  switch (op){ /* opの値をみる. */
    case '+': /* '+'の場合 */
      result = a + b; /* a + bの値をresultに代入. */
      break; /* ここで分岐処理を抜ける. */
    case '-': /* '-'の場合 */
      result = a - b; /* a - bの値をresultに代入. */
      break; /* ここで分岐処理を抜ける. */
    case '*': /* '*'の場合 */
      result = a * b; /* a * bの値をresultに代入. */
      break; /* ここで分岐処理を抜ける. */
    case '/': /* '/'の場合 */
      if (b == 0){ /* bが0ならゼロで除算してしまうのでエラー処理. */
        printf("Error: Division by zero.\n"); /* "Division by zero."というエラーメッセージを出力. */
        return -2; /* プログラムの異常終了 */
      }
      result = a / b; /* a / bの値をresultに代入. */
      break; /* ここで分岐処理を抜ける. */
    default: /* 上記以外 */
      printf("Error: op( = %c) is invalid.\n", op); /* 上のどれにも当てはまらない場合は, "op is invalid."とエラー出力. */
      return  -1; /* プログラムの異常終了 */
  }

  /* 結果の出力 */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* プログラムの終了 */
  return 0;

}
