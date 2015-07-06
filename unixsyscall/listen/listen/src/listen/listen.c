/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdio.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* ソケットファイルディスクリプタsoc */
  struct sockaddr_in addr; /* IPアドレスやポート番号などのIPv4インターネット情報を持つsockaddr_in構造体addr */

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをfdに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */

  /* バインドするアドレス情報addrの設定. */
  addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  addr.sin_port = htons(3000); /* ポート番号3000番をhtonsで変換してセット. */
  addr.sin_addr.s_addr = INADDR_ANY; /* すべてのローカルインターフェイスにバインドする. */

  /* socにaddrをバインド(紐付け)する. */
  if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) == -1){ /* 戻り値が-1の時はエラー. */

    /* エラー処理 */
    printf("bind error!\n"); /* "bind error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"bind success." */
  printf("bind success.\n"); /* printfで"bind success."と出力. */

  /* リッスン(待ち受け)開始. */
  if (listen(soc, 5) == -1){ /* listenで上限5つまで接続を待ち受ける.(戻り値が-1の時はエラー.) */

    /* エラー処理 */
    printf("listen error!\n"); /* "listen error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"listen success." */
  printf("listen success.\n"); /* printfで"listen success."と出力. */

  /* ソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
