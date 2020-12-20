/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <bluetooth/bluetooth.h> /* Bluetooth */
#include <bluetooth/rfcomm.h> /* RFCOMM */

/* main関数 */
int main(void){

  /* 変数の初期化. */
  int soc = -1; /* Bluetoothソケットを-1で初期化. */
  struct sockaddr_rc local_addr = {0}; /* local_addrを{0}で初期化. */
  struct sockaddr_rc remote_addr = {0}; /* remote_addrを{0}で初期化. */

  /* Bluetooth(RFCOMM)のソケット作成 */
  soc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM); /* socketにAF_BLUETOOTHとBTPROTO_RFCOMMをセットしてsocを作成. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* ソケットの値を出力. */
  printf("soc = %d\n", soc); /* socを出力. */

  /* バインドするアドレス情報の設定. */
  local_addr.rc_family = AF_BLUETOOTH; /* Bluetoothアドレスファミリー */
  local_addr.rc_bdaddr = *BDADDR_ANY; /* BDADDR_ANY */
  local_addr.rc_channel = (uint8_t)1; /* とりあえず1. */

  /* socにlocal_addrをバインドする. */
  if (bind(soc, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1){ /* bindが-1ならエラー. */

    /* エラー処理 */
    printf("bind error!\n"); /* "bind error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"bind success." */
  printf("bind success.\n"); /* "bind success."と出力. */

  /* ソケットを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
