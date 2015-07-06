/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* AF_INET, AF_INET6アドレス・ファミリー */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  struct in_addr addr; /* アドレスを格納するin_addr構造体変数addr. */

  /* IPアドレス文字列をin_addr_tの形式に変換. */
  inet_aton("1.2.3.4", &addr); /* inet_atonでIPアドレス文字列をaddrのメンバs_addrに, in_addr_t形式(実態はuint32_t)に変換して格納. */

  /* addrの内容を出力. */
  printf("addr.s_addr = 0x%08x\n", addr.s_addr); /* printfでaddr.s_addrの値を16進数で出力. */

  /* プログラムの終了 */
  return 0;

}
