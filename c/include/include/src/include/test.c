/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "test.h" /* #include文で関数funcが宣言されているtest.hを("")で括った場合はこのソースの位置から探して取り込む. */
/* 既定のヘッダファイル */
#include <stdio.h> /* #include文で標準関数printfが宣言されているstdio.hを(<>)で括った場合はシステムのインクルードパス(/usr/includeなど)の位置から探して取り込む. */

/* 関数の定義 */
/* 関数funcの定義 */
void func(void){ /* 文字列を出力する関数func. */

  /* 文字列"func"を出力. */
  printf("func\n"); /* printfで"func"を出力. */

}
