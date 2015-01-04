/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int a; /* int型変数a */
  int b; /* int型変数b */
  char op; /* 入力された演算子記号文字を格納するchar型変数op. */
  int result; /* 結果を格納するint型変数result. */

  /* aの入力 */
  printf("a: "); /* aの入力フォーム */
  scanf("%d", &a); /* 入力された整数値をaに格納. */

  /* opの入力 */
  printf("op('+', '-', '*', '/'): "); /* opの入力フォーム */
  scanf("%*c%c", &op); /* 入力された演算子記号文字をopに格納. */
  if (op != '+' && op != '-' && op != '*' && op != '/'){ /* opが'+', '-', '*', '/'のどれでもない場合は, エラー終了. */
    printf("Error: op( = %c) is invalid.\n", op); /* "op is invalid."というエラーメッセージを出力. */
    return -1; /* プログラムの異常終了 */
  }

  /* bの入力 */
  printf("b: "); /* bの入力フォーム */
  scanf("%d", &b); /* 入力された整数値をbに格納. */
  if (op == '/' && b == 0){ /* 除算かつbが0の場合は, 0で除算してしまうのでエラー終了. */
    printf("Error: Division by zero.\n"); /* "Division by zero."というエラーメッセージを出力. */
    return -2; /* プログラムの異常終了 */
  }

  /* opごとに処理を分岐. */
  if (op == '+'){ /* '+'ならaとbを加算. */
    result = a + b; /* a + bの値をresultに代入. */
  }
  else if (op == '-'){ /* '-'ならaとbを減算. */
    result = a - b; /* a - bの値をresultに代入. */
  }
  else if (op == '*'){ /* '*'ならaとbを乗算. */
    result = a * b; /* a * bの値をresultに代入. */
  }
  else{ /* それ以外('/'のとき)ならaとbの除算. */
    result = a / b; /* a / bの値をresultに代入. */
  }

  /* 結果の出力 */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* プログラムの終了 */
  return 0;

}
