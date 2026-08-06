/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* インターネットプロトコル */
 
/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* ソケットファイルディスクリプタsoc */
  int type; /* ソケット種別type */
  socklen_t len; /* getsockoptのサイズ */
  int ret; /* getsockoptの戻り値 */
 
  /* RAWソケットの作成(root権限が必要.) */
  soc = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); /* SOCK_RAW指定でRAWソケットを作成し, socに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }
 
  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */
 
  /* SO_TYPEでソケット種別を取得. */
  len = sizeof(type);
  ret = getsockopt(soc, SOL_SOCKET, SO_TYPE, &type, &len); /* getsockoptでSO_TYPEを取得し, retに格納. */
  if (ret == -1){ /* retが-1の時はエラー. */

    /* エラー処理 */
    printf("getsockopt error!\n"); /* "getsockopt error!"と出力. */
    close(soc);
    return -1; /* -1を返す. */

  }
 
  /* typeの値を出力. */
  printf("type = %d\n", type); /* printfでtypeの値を出力. */
  if (type == SOCK_RAW){ /* typeがSOCK_RAWの時. */
    printf("SOCK_RAW\n"); /* "SOCK_RAW"と出力. */
  }
 
  /* RAWソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */
 
  /* プログラムの終了 */
  return 0;

}
