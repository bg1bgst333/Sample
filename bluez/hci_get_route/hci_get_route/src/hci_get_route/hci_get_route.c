/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <bluetooth/bluetooth.h> /* Bluetooth */
#include <bluetooth/hci.h> /* HCI */
#include <bluetooth/hci_lib.h> /* HCIライブラリ */ 

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int dev_id; /* デバイスID */

  /* デバイスIDの取得 */
  dev_id = hci_get_route(NULL); /* hci_get_routeでdev_idを取得. */

  /* デバイスIDの出力 */
  printf("dev_id = %d\n"); /* dev_idの出力. */

  /* プログラムの終了 */
  return 0; /* 0を返す. */

}
