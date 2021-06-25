/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <stdlib.h> /* 標準ライブラリ */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* AF_INET, AF_INET6アドレス・ファミリー */
#include <arpa/inet.h> /* IPアドレス変換 */
#include <netdb.h> /* ホスト名変換 */

/* main関数の定義 */
int main(int argc, char *argv[]){ /* argcは引数の個数, argvは各引数文字列へのポインタを格納した配列. */

  /* 変数の宣言 */
  struct hostent *host; /* ホスト情報を格納するhostent構造体へのポインタhost. */
  int port; /* 接続ポート番号. */
  int soc; /* 接続するクライアントのソケットファイルディスクリプタsoc. */
  struct sockaddr_in target_addr; /* 接続先サーバのIPアドレスやポート番号などの情報target_addr. */
  char request_str[1024]; /* リクエスト文字列request_str.(長さ1024) */
  int send_len; /* 送信したメッセージ文字列の長さsend_len. */
  char response_buf[4096]; /* レスポンスバッファresponse_buf.(長さ4096) */
  int recv_len; /* 受信したメッセージ文字列の長さrecv_len. */
  int content_len; /* Content-Length値content_len. */
  char content_len_str[256]; /* Content-Length行の文字列content_len_str */

  /* main関数の引数が5つの時以外は終了. */
  if (argc != 5){ /* 5つではない. */

    /* "Not enough input arguments."と出力. */
    printf("Not enough input arguments.\n"); /* printfで"Not enough input arguments."と出力. */
    return -1; /* -1を返して終了. */

  }

  /* ホスト情報の取得 */
  host = gethostbyname(argv[1]); /* gethostbynameで指定したホスト名のホスト情報を取得. */
  if (host == NULL){ /* hostがNULLなら. */

    /* エラー */
    printf("gethostbyname error!\n"); /* エラーメッセージ出力 */
    return -2; /* -2を返して終了. */

  }

  /* ポート番号の変換 */
  port = atoi(argv[2]); /* atoiで, argv[2]をint型に変換し, portに格納. */

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをsocに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー */
    printf("socket error!\n"); /* エラーメッセージ出力 */
    return -3; /* -3を返して終了. */

  }

  /* 接続先サーバ情報target_addrの設定. */
  target_addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  target_addr.sin_port = htons(port); /* 入力したポート番号port. */
  target_addr.sin_addr.s_addr = *(in_addr_t *)host->h_addr_list[0]; /* hostのIPアドレス情報をセット. */

  /* 接続 */
  if (connect(soc, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1){ /* connectで接続先サーバに接続.(-1が返ったらエラー.) */

    /* エラー処理 */
    printf("connect error!\n"); /* "connect error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -4; /* -4を返して終了. */

  }

  /* 成功したら"connect success." */
  printf("connect success.\n"); /* printfで"connect success."と出力. */

  /* リクエスト文字列のクリア. */
  memset(request_str, 0, sizeof(char) * 1024); /* memsetでrequest_strを0で埋める. */

  /* リクエスト文字列のセット. */
  sprintf(request_str, "POST %s HTTP/1.0\r\n", argv[3]); /* sprintfでPOSTリクエストをセット. */
  sprintf(content_len_str, "Content-Length: %d\r\n", strlen(argv[4])); /* Content-Lengthの行を組み立て. */  
  strcat(request_str, content_len_str); /* content_len_strを連結. */
  strcat(request_str, "Content-Type: text/plain\r\n"); /* Content-Typeの行を連結. */
  strcat(request_str, "\r\n"); /* 1行空ける. */
  strcat(request_str, argv[4]); /* argv[4]を連結. */

  /* 送信 */
  send_len = send(soc, request_str, strlen(request_str), 0); /* sendでrequest_strを送信. */

  /* レスポンス文字列のクリア. */
  memset(response_buf, 0, sizeof(char) * 4096); /* memsetでresponse_bufを0で埋める. */

  /* 受信 */
  recv_len = recv(soc, response_buf, sizeof(char) * 4096, 0); /* 受信したメッセージをresponse_bufに格納. */

  /* レスポンス文字列を出力. */
  printf("%s\n", response_buf); /* response_bufを出力. */

  /* クライアントソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
