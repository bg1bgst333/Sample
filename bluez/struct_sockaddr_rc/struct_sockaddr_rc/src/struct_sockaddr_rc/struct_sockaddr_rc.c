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
  int remote_addr_len = 0; /* remote_addr_lenを0で初期化. */
  int acc = -1; /* 待ち受けソケットを-1で初期化. */
  char remote_addr_str[1024] = {0}; /* リモートアドレス文字列を{0}で初期化. */

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
  local_addr.rc_channel = (uint8_t)22; /* チャンネルは22とする. */

  /* socにlocal_addrをバインドする. */
  if (bind(soc, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1){ /* bindが-1ならエラー. */

    /* エラー処理 */
    printf("bind error!\n"); /* "bind error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"bind success." */
  printf("bind success.\n"); /* "bind success."と出力. */

  /* リッスン開始. */
  if (listen(soc, 1) == -1){ /* listenで1つだけ待ち受ける. */

    /* エラー処理 */
    printf("listen error!\n"); /* "listen error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"listen success." */
  printf("listen success.\n"); /* "listen success."と出力. */

  /* remote_addr_lenのセット. */
  remote_addr_len = sizeof(remote_addr); /* sizeof(remote_addr)をセット. */

  /* アクセプト開始. */
  acc = accept(soc, (struct sockaddr *)&remote_addr, &remote_addr_len); /* acceptでアクセプトしたら, アクセプトソケットをaccに格納. */
  if (acc == -1){ /* accが-1ならエラー. */

    /* エラー処理 */
    printf("accept error!\n"); /* "accept error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* リモートアドレスの出力. */
  ba2str(&remote_addr.rc_bdaddr, remote_addr_str); /* ba2strで文字列に変換. */
  printf("accept!(Bluetooth Address = %s)\n", remote_addr_str); /* remote_addr_strを出力. */

  /* ソケットを閉じる. */
  close(acc); /* closeでaccを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
