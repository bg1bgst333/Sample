/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/socket.h> /* ソケット */
#include <sys/types.h> /* 派生型 */
#include <arpa/inet.h> /* IPアドレス変換 */
#include <netdb.h> /* ホスト名変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  char hostname[256]; /* ホスト名hostname. */
  struct hostent *host; /* ホスト情報を格納するhostent構造体へのポインタhost. */
  struct in_addr addr; /* in_addr構造体addr */
  char *host_str; /* 最終的に元に戻したホスト名文字列. */

  /* ホスト名の入力 */
  printf("hostname: "); /* hostnameの入力フォーム */
  scanf("%s", hostname); /* 入力されたホスト名をhostnameに格納. */

  /* ホスト情報の取得 */
  host = gethostbyname(hostname); /* gethostbynameで指定したホスト名のホスト情報を取得. */
  if (host == NULL){ /* hostがNULLなら. */

    /* エラー */
    printf("gethostbyname error!\n"); /* エラーメッセージ出力. */
    return -1; /* -1を返して終了. */

  }

  /* ホスト名から導き出されたIPアドレス情報は, h_addr_list[0]に文字列として格納されているが, 実際は以下の用に格納されている. */
  printf("host->h_addr_list[0][0] = %02x, host->h_addr_list[0][1] = %02x, host->h_addr_list[0][3] = %02x, host->h_addr_list[0][3] = %02x\n", host->h_addr_list[0][0], host->h_addr_list[0][1], host->h_addr_list[0][2], host->h_addr_list[0][3]); /* これはin_addr_t(つまりuint_32t)と同じ形式. なのでin_addrのs_addrに格納して使うことができる. */

  /* in_addr_tの変数に格納. */
  addr.s_addr = *(in_addr_t *)host->h_addr_list[0]; /* h_addr_list[0]はchar *なので, in_addr *にキャストし, さらに*で参照先の値をaddr.s_addrに格納する. */

  /* addr.s_addrを出力. */
  printf("addr.s_addr = %08x\n", addr.s_addr); /* addr.s_addrを16進整数として出力. */

  /* inet_ntoaでまたホスト名文字列に戻す. */
  host_str = inet_ntoa(addr); /* inet_ntoaでaddrを変換. */

  /* host_strの出力. */
  printf("host_str = %s\n", host_str); /* printfでhost_strを出力. */

  /* プログラムの終了 */
  return 0;

}
