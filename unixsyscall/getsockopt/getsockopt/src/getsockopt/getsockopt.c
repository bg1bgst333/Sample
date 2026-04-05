/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <unistd.h> /* UNIX標準 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int sock_tcp;
  int sock_udp;
  int type;
  int len;
  int ret;

  /* TCPソケット作成 */
  sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_tcp < 0){
    perror("socket(TCP)");
    exit(1);
  }

  /* UDPソケット作成 */
  sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_udp < 0){
    close(sock_tcp);
    perror("socket(UDP)");
    exit(1);
  }

  /* TCPにてSO_TYPE取得. */
  len = sizeof(type);
  ret = getsockopt(sock_tcp, SOL_SOCKET, SO_TYPE, &type, &len);
  if (ret < 0){
    perror("getsockopt(TCP)");
    close(sock_udp);
    close(sock_tcp);
    exit(1);
  }
  printf("type = %d ", type);
  if (type == SOCK_STREAM){
    printf("(SOCK_STREAM)\n");
  }
  else{
    printf("(Unknown)\n");
  }

  /* UDPにてSO_TYPE取得. */
  len = sizeof(type);
  ret = getsockopt(sock_udp, SOL_SOCKET, SO_TYPE, &type, &len);
  if (ret < 0){
    perror("getsockopt(UDP)");
    close(sock_udp);
    close(sock_tcp);
    exit(1);
  }
  printf("type = %d ", type);
  if (type == SOCK_DGRAM){
    printf("(SOCK_DGRAM)\n");
  }
  else{
    printf("(Unknown)\n");
  }

  /* 終了処理 */
  close(sock_udp);
  close(sock_tcp);
  return 0;

}
