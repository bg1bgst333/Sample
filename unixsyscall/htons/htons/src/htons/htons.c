/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  u_short ns_port; /* ネットワークバイトオーダに変換した後のポート番号. */

  /* ポート番号の変換 */
  ns_port = htons(3000); /* ポート番号3000番をネットワークバイトオーダに変換. */

  /* 出力 */
  printf("ns_port = %04x\n", ns_port); /* ns_portを16進数で出力. */

  /* プログラムの終了 */
  return 0;

}
