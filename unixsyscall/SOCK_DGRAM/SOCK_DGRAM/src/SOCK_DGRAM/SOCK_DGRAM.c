/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* ソケットファイルディスクリプタsoc */

  /* UDPソケットの作成 */
  soc = socket(AF_INET, SOCK_DGRAM, 0); /* SOCK_DGRAM指定でUDPソケットを作成し, socに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */

  /* UDPソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
