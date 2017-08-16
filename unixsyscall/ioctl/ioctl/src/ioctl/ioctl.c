/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/socket.h> /* ソケット */
#include <sys/types.h> /* 派生型 */
#include <sys/ioctl.h> /* IO制御 */
#include <net/if.h> /* ネットワークインターフェース */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  char interface_name[256]; /* インターフェース名interface_name. */
  struct ifreq sifr; /* インターフェース情報の設定と取得を行うのに使用するリクエストsifr. */
  int soc; /* ソケットファイルディスクリプタsoc. */
  char *ip_str; /* IPアドレス文字列へのポインタip_str. */
  struct sockaddr_in *addr_in; /* struct sockaddr_inポインタaddr_in. */

  /* インターフェース名の入力. */
  printf("interface_name: "); /* interface_nameの入力フォーム */
  scanf("%s", interface_name); /* 入力されたインターフェース名をinterface_nameに格納. */

  /* ソケットの作成. */
  soc = socket(AF_INET, SOCK_DGRAM, 0); /* socketでsocを作成. */
  if (soc == -1){ /* -1だとエラー. */
    perror("socket error!"); /* perrorで"socket error!"と出力. */
    return -1; /* -1を返して異常終了. */
  }

  /* sifrの設定. */
  sifr.ifr_addr.sa_family = AF_INET; /* sifr.ifr_addr.sa_familyにAF_INETをセット. */
  strncpy(sifr.ifr_name, interface_name, IFNAMSIZ - 1); /* sifr.ifr_nameにinterface_nameをセット.(IFNAMSIZE - 1を超えないようにコピー.) */

  /* IPアドレスの取得. */
  if (ioctl(soc, SIOCGIFADDR, &sifr) < 0){ /* ioctlでSIOCGIFADDRを送る.(0未満ならエラー.) */
    perror("ioctl error!"); /* perrorで"ioctl error!"を出力. */
    close(soc); /* closeでsocを閉じる. */
    return -2; /* -2を返して異常終了. */
  }

  /* IPアドレスの出力. */
  addr_in = (struct sockaddr_in *)&sifr.ifr_addr; /* sifr.ifr_addrのアドレスをaddr_inに変換. */
  ip_str = inet_ntoa(addr_in->sin_addr); /* inet_ntoaにaddr_in->sin_addrを渡すと, ip_strにIP文字列へのポインタが渡される. */
  printf("%s ip address = %s\n", interface_name, ip_str); /* interface_nameとip_strを出力. */

  /* ソケットを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
