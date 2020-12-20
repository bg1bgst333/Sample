/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <bluetooth/bluetooth.h> /* Bluetooth */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int soc; /* Bluetoothソケット */

  /* Bluetooth(RFCOMM)のソケット作成 */
  soc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM); /* socketにAF_BLUETOOTHとBTPROTO_RFCOMMをセットしてsocを作成. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* ソケットの値を出力. */
  printf("soc = %d\n", soc); /* socを出力. */

  /* ソケットを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
