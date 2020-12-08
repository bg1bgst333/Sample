/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <bluetooth/bluetooth.h> /* Bluetooth */
#include <bluetooth/hci.h> /* HCI */
#include <bluetooth/hci_lib.h> /* HCIライブラリ */ 

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int dev_id; /* デバイスID */
  int soc; /* Bluetoothソケット */
  /* デバイスIDの取得 */
  dev_id = hci_get_route(NULL); /* hci_get_routeでdev_idを取得. */
  if (dev_id >= 0){ /* 0以上なら成功. */

    /* デバイスIDの出力 */
    printf("dev_id = %d\n", dev_id); /* dev_idの出力 */

    /* Bluetoothソケットを開く. */
    soc = hci_open_dev(dev_id); /* hci_open_devにdev_idを渡してBluetoothソケットsocを開く. */
    if (soc >= 0){ /* 0以上なら成功. */

      /* Bluetoothソケットファイルディスクリプタの出力 */
      printf("soc = %d\n", soc); /* socの出力 */

      /* Bluetoothソケットを閉じる. */
      close(soc); /* closeでsocを閉じる. */      

      /* プログラムの終了 */
      return 0; /* 0を返して正常修了. */

    }

  }

  /* プログラムの終了 */
  return -1; /* -1を返して異常終了. */

}
