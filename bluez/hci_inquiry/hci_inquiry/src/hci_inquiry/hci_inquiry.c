/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <unistd.h> /* UNIX標準 */
#include <bluetooth/bluetooth.h> /* Bluetooth */
#include <bluetooth/hci.h> /* HCI */
#include <bluetooth/hci_lib.h> /* HCIライブラリ */ 

/* main関数 */
int main(void){

  /* 変数の宣言 */
  int dev_id; /* デバイスID */
  int soc; /* Bluetoothソケット */
  inquiry_info *ii; /* 接続先情報リストへのポインタ. */
  int num_rsp; /* 接続先の数 */
  int ret; /* プログラムの戻り値 */

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

      /* 接続先情報リストを格納するためのバッファ確保. */
      ii = (inquiry_info *)malloc(sizeof(inquiry_info) * 255); /* mallocでメモリ確保し, ポインタiiに格納. */

      /* 接続先情報リストの取得 */
      ret = -2; /* 最初は-2(異常終了)にしておく. */
      num_rsp = hci_inquiry(dev_id, 8, 255, NULL, &ii, IREQ_CACHE_FLUSH); /* hci_inquiryで接続先情報リストを取得し, iiに格納.(戻り値の接続先の数はnum_rspに格納. */
      if (num_rsp >= 0){ /* 0以上なら成功. */

        /* 接続先の数を出力. */
        printf("num_rsp = %d\n", num_rsp); /* num_rspを出力. */
        ret = 0; /* 正常終了 */

      }

      /* 解放 */
      free(ii); /* iiを解放. */   
      
      /* Bluetoothソケットを閉じる. */
      close(soc); /* closeでsocを閉じる. */      

      /* プログラムの終了 */
      return ret; /* retを返す. */

    }

  }

  /* プログラムの終了 */
  return -1; /* -1を返して異常終了. */

}
