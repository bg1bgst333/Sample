/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <arpa/inet.h> /* IPアドレス変換 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  int soc; /* ソケットファイルディスクリプタsoc */
  struct sockaddr_in server_addr; /* IPアドレスやポート番号などのIPv4インターネット情報を持つサーバのsockaddr_in構造体server_addr. */
  int optval = 1; /* セットするオプションの値optvalを1に初期化. */
  char buf[256]; /* クライアントからのメッセージ文字列を受け取るバッファbuf.(長さ256) */
  int exit_flg = 0; /* メッセージ処理ループを抜けるかどうかのフラグexit_flg.(exit_flg == 1のとき, メッセージ処理ループから抜ける.) */
  struct sockaddr_in client_addr; /* クライアントのsockaddr_in構造体client_addr. */
  int client_addr_len; /* クライアントのsockaddr_in構造体client_addrの長さclient_addr_len. */
  int recv_len; /* 受信したメッセージ文字列の長さrecv_len. */
  char *client_ip_addr_str; /* クライアントのIPアドレス文字列へのポインタclient_ip_addr_str. */
  u_short client_port; /* クライアントのポート番号client_port. */

  /* UDPソケットの作成 */
  soc = socket(AF_INET, SOCK_DGRAM, 0); /* SOCK_DGRAM指定でUDPソケットを作成し, socに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* socの値を出力. */
  printf("soc = %d\n", soc); /* printfでsocの値を出力. */

  /* バインドするアドレス情報server_addrの設定. */
  server_addr.sin_family = AF_INET; /* IPv4インターネットのアドレス・ファミリーAF_INET */
  server_addr.sin_port = htons(3000); /* ポート番号3000番をhtonsで変換してセット. */
  server_addr.sin_addr.s_addr = INADDR_ANY; /* すべてのローカルインターフェイスにバインドする. */

  /* オプションSO_REUSEADDRの有効化. */
  if (setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, (const char *)&optval, sizeof(optval)) == -1){ /* setsockoptでSO_REUSEADDRを有効化.(-1ならエラー.) */

    /* エラー処理 */
    printf("setsockopt(SO_REUSEADDR) error!\n"); /* "setsockopt(SO_REUSEADDR) error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"setsockopt(SO_REUSEADDR) success." */
  printf("setsockopt(SO_REUSEADDR) success.\n"); /* printfで"setsockopt(SO_REUSEADDR) success."と出力. */

  /* socにserver_addrをバインド(紐付け)する. */
  if (bind(soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){ /* 戻り値が-1の時はエラー. */

    /* エラー処理 */
    printf("bind error!\n"); /* "bind error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"bind success." */
  printf("bind success.\n"); /* printfで"bind success."と出力. */

  /* メッセージ処理ループ */
  while (!exit_flg){ /* exit_flg == 1なら, このループから抜ける. */

    /* バッファをクリア. */
    memset(buf, 0, sizeof(char) * 256); /* memsetでbufを0で埋める. */

    /* client_addr_lenのセット. */
    client_addr_len = sizeof(client_addr); /* client_addr_lenにsizeof(client_addr)でサイズをセット. */

    /* 受信 */
    recv_len = recvfrom(soc, buf, sizeof(char) * 256, 0, (struct sockaddr *)&client_addr, &client_addr_len); /* recvfromで読み込み. */

    /* クライアント情報の取得. */
    client_ip_addr_str = inet_ntoa(client_addr.sin_addr); /* inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換. */
    client_port = ntohs(client_addr.sin_port); /* ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換. */

    /* 改行コードの除去 */
    buf[recv_len - 1] = '\0'; /* "\n"がbufに入ってしまうので, 最後の文字から"\n"を除去. */

    /* クライアント情報の表示. */
    printf("IPAddress = %s, Port = %hu, Message = %s\n", client_ip_addr_str, client_port, buf); /* IPアドレスとポートとメッセージを表示. */

    /* "end"が格納されていたら, メッセージ処理ループを抜ける. */
    if (strcmp(buf, "end") == 0){ /* strcmpでbufが"end"なら. */

      /* 抜ける. */
      exit_flg = 1; /* exitを1とする. */

    }

  }

  /* UDPソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
