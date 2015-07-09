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
  int soc; /* リッスン(待ち受け)するサーバのソケットファイルディスクリプタsoc. */
  struct sockaddr_in server_addr; /* IPアドレスやポート番号などのIPv4インターネット情報を持つサーバのsockaddr_in構造体server_addr. */
  int optval = 1; /* セットするオプションの値optvalを1に初期化. */
  int acc; /* アクセプト(接続を受理)したクライアントのソケットファイルディスクリプタacc. */
  struct sockaddr_in client_addr; /* クライアントのsockaddr_in構造体client_addr. */
  int client_addr_len; /* クライアントのsockaddr_in構造体client_addrの長さclient_addr_len. */
  char *client_ip_addr_str; /* クライアントのIPアドレス文字列へのポインタclient_ip_addr_str. */
  u_short client_port; /* クライアントのポート番号client_port. */
  char buf[256]; /* クライアントからのメッセージ文字列を受け取るバッファbuf.(長さ256) */
  int exit_flg = 0; /* メッセージ処理ループを抜けるかどうかのフラグexit_flg.(exit_flg == 1のとき, メッセージ処理ループから抜ける.) */
  int recv_len; /* 受信したメッセージ文字列の長さrecv_len. */

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをfdに格納. */
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

  /* リッスン(待ち受け)開始. */
  if (listen(soc, 5) == -1){ /* listenで上限5つまで接続を待ち受ける.(戻り値が-1の時はエラー.) */

    /* エラー処理 */
    printf("listen error!\n"); /* "listen error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* 成功したら"listen success." */
  printf("listen success.\n"); /* printfで"listen success."と出力. */

  /* acceptに渡すclient_addr_lenのセット. */
  client_addr_len = sizeof(client_addr); /* client_addr_lenにsizeof(client_addr)でサイズをセット.(これをやらないと, クライアント情報がclient_addrに格納されない.) */

  /* アクセプト(接続受理)待ち */
  acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len); /* acceptでアクセプトしたら, クライアントソケットをaccに格納. */
  if (acc == -1){ /* accが-1の時はエラー. */

    /* エラー処理 */
    printf("accept error!\n"); /* "accept error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -1; /* -1を返す. */

  }

  /* クライアント情報の表示 */
  client_ip_addr_str = inet_ntoa(client_addr.sin_addr); /* inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換. */
  client_port = ntohs(client_addr.sin_port); /* ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換. */
  printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port); /* IPアドレスとポートを表示. */

  /* メッセージ処理ループ */
  while (!exit_flg){ /* exit_flg == 1なら, このループから抜ける. */

    /* バッファをクリア. */
    memset(buf, 0, sizeof(char) * 256); /* memsetでbufを0で埋める. */

    /* クライアントからのメッセージを受け取る. */
    recv_len = recv(acc, buf, sizeof(char) * 256, 0); /* recvでaccからのメッセージを読込み, bufに格納.(読み込んだメッセージの長さをrecv_lenに格納.) */

    /* 改行コードの除去 */
    buf[recv_len - 1] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後の文字から"\n"を除去. */
    buf[recv_len - 2] = '\0'; /* "\r\n"がbufに入ってしまうので, 最後から2番目の文字から"\r"を除去. */

    /* "end"が格納されていたら, メッセージ処理ループを抜ける. */
    if (strcmp(buf, "end") == 0){ /* strcmpでbufが"end"なら. */

      /* 抜ける. */
      exit_flg = 1; /* exitを1とする. */

    }
    else{ /* そうでない場合は標準出力に出力した後, 改行コードを再び付けてクライアントに送り返す. */

      /* bufの内容を出力. */
      printf("%s\n", buf); /* printfでbufの内容を出力. */

      /* 除去した改行コードを再び付ける. */
      buf[recv_len - 1] = '\n'; /* '\n'を付ける. */
      buf[recv_len - 2] = '\r'; /* '\r'を付ける. */

      /* bufの内容を送り返す. */
      send(acc, buf, strlen(buf), 0); /* sendでbufの内容を返す. */

    }

  }

  /* アクセプトしたクライアントソケットファイルディスクリプタを閉じる. */
  close(acc); /* closeでaccを閉じる. */

  /* サーバソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0;

}
