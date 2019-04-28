/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* main関数の定義 */
int main(void){

  /* 初期化 */
  char target[] = "ABC,DEF,GHI\nJKL MNO PQR"; /* targetを"ABC,DEF,GHI\nJKL MNO PQR"で初期化. */
  char *s = target; /* 文字列の開始位置sをtargetの先頭アドレスで初期化. */
  char *p = NULL; /* トークンのアドレスpをNULLで初期化. */
  int d = 0; /* 距離dを0で初期化. */
  char token[256] = {0}; /* tokenを{0}で初期化. */
  char *e = &target[strlen(target)]; /* eを最後の文字の次のNULL文字('\0')のアドレスで初期化. */

  /* do-while文でトークン切り出し. */
  do{ /* do-while文 */

    /* 文字列を渡して, トークンを取得. */
    p = strpbrk(s, ",\n "); /* ",\n "のいずれかで区切り, トークンのアドレスをpに格納. */
    if (p != NULL){ /* pがNULLでない場合. */
      d = p - s; /* pからsを引くと, ポインタ演算により, 距離dが求められる. */
      strncpy(token, s, d); /* tokenにsからd文字分コピー. */
      printf("token = %s\n", token); /* tokenを出力. */
      s = p + 1; /* sをp + 1に再設定する. */
    }
    else{ /* pがNULLの場合. */
      d = e - s; /* eからsを引くと, ポインタ演算により, 距離dが求められる. */
      strncpy(token, s, d); /* tokenにsからd文字分コピー. */
      printf("token = %s\n", token); /* tokenを出力. */
    }

  }
  while (p != NULL); /* pがNULLでない間は繰り返す. */

  /* 最後にtargetを出力. */
  printf("target = %s\n", target); /* targetを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
