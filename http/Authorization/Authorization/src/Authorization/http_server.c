/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <stdlib.h> /* 標準ライブラリ */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* AF_INET, AF_INET6アドレス・ファミリー */
#include <arpa/inet.h> /* IPアドレス変換 */
#include <signal.h> /* シグナル */
#include <time.h> /* UNIX時間 */
#include <openssl/bio.h> /* BIO */
#include <openssl/evp.h> /* EVP(BIO_f_base64) */
#include <openssl/err.h> /* エラー */
#include <openssl/buffer.h> /* バッファ */

/* モジュール変数の宣言 */
int server_soc; /* サーバソケットserver_soc */

/* 関数のプロトタイプ宣言 */
void quit_signal_handler(int sig); /* 終了シグナル */
int create_http_server_socket(int port, struct sockaddr_in *server_addr); /* HTTPサーバソケット作成. */
int accept_loop(int soc); /* アクセプトループ */ 

/* main関数の定義 */
int main(int argc, char *argv[]){ /* argcは引数の個数, argvは各引数文字列へのポインタを格納した配列. */

  /* 変数の宣言 */
  int port; /* 待ち受けポート番号. */
  struct sockaddr_in server_addr; /* サーバアドレスserver_addr */

  /* main関数の引数が2つの時以外は終了. */
  if (argc != 2){ /* 2つではない. */

    /* "Not enough input arguments."と出力. */
    printf("Not enough input arguments.\n"); /* printfで"Not enough input arguments."と出力. */
    return -1; /* -1を返して異常終了. */

  }

  /* argv[1]をポート番号として受け取る. */
  port = atoi(argv[1]); /* atoiで, argv[1]をint型に変換し, portに格納. */

  /* シグナルハンドラのセット */
  signal(SIGINT, quit_signal_handler); /* signalでquit_signal_handlerをセット. */

  /* サーバソケット作成とリッスン. */
  server_soc = create_http_server_socket(port, &server_addr); /* create_http_server_socketでサーバソケットを作成し, server_socに格納. */
  if (server_soc < 0){ /* 0未満は失敗. */
    printf("Create HTTP Server Socket failed!\n"); /* printfで"Create HTTP Server Socket failed!\n"と出力. */
    return -2; /* -2を返して異常終了. */
  }

  /* "Create Server Socket and Listen."と出力. */
  printf("Create Server Socket and Listen.\n"); /* "Create Server Socket and Listen."と出力. */

  /* アクセプトループ */
  accept_loop(server_soc); /* accept_loopでアクセプト. */

  /* サーバソケットを閉じる. */
  close(server_soc); /* closeでserver_socを閉じる. */

  /* 正常終了 */
  return 0; /* 0を返して正常終了. */

}

/* 終了シグナル */
void quit_signal_handler(int sig){

  /* 受け取ったシグナルを出力. */
  printf("sig = %d\n", sig); /* sigを出力. */

  /* サーバソケットを閉じる. */
  close(server_soc); /* closeでserver_socを閉じる. */
  exit(-1); /* -1を返して強制終了. */

}

/* HTTPサーバソケット作成 */
int create_http_server_socket(int port, struct sockaddr_in *server_addr){

  /* 変数の初期化 */
  int soc = -1; /* ソケットsocを-1で初期化. */
  int yes = 1; /* アドレス再利用yesを1で初期化. */

  /* ソケット作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, socに格納. */
  if (soc < 0){ /* 0未満はエラー. */
    perror("socket"); /* "socket"エラー. */
    return -1; /* -1を返して異常終了. */
  }

  /* ソケットオプション設定 */
  setsockopt(soc, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes)); /* アドレス再利用をyesでセット. */

  /* バインド */
  server_addr->sin_family = AF_INET; /* ファミリーはAF_INET. */
  server_addr->sin_port = htons(port); /* ポートはport.(htonsで変換すること.) */
  server_addr->sin_addr.s_addr = INADDR_ANY; /* 受け付けはどこでも可. */
  if (bind(soc, (struct sockaddr *)server_addr, sizeof(struct sockaddr_in)) != 0){ /* 0以外なら失敗. */
    perror("bind"); /* "bind"エラー. */
    close(soc); /* closeでsocを閉じる. */
    return -2; /* -2を返して異常終了. */
  }

  /* リッスン */
  if (listen(soc, 5) != 0){ /* 0以外なら失敗. */
    perror("listen"); /* "listen"エラー. */
    close(soc); /* closeでsocを閉じる. */
    return -3; /* -3を返して異常終了. */
  }

  /* 成功ならsocを返す. */
  return soc; /* socを返す. */

}

/* アクセプトループ */
int accept_loop(int soc){

  /* 変数の宣言と初期化. */
  struct sockaddr_in client_addr; /* クライアントアドレスclient_addr */
  int client_addr_len; /* client_addrの長さclient_addr_len. */
  int acc; /* アクセプトソケットacc */
  char *client_ip_addr_str; /* クライアントのIPアドレス文字列へのポインタclient_ip_addr_str. */
  u_short client_port; /* クライアントのポート番号client_port. */
  int ret = 0; /* ループ抜ける時の理由ret. */
  char recv_buf[4096] = {0}; /* recv_buf(長さ4096)を{0}で初期化. */
  char send_buf[4096] = {0}; /* send_buf(長さ4096)を{0}で初期化. */
  char response_header[4096] = {0}; /* response_header(長さ4096)を{0}で初期化. */
  char response_body[4096] = {0}; /* response_body(長さ4096)を{0}で初期化. */
  time_t t; /* 現在のUNIX時間t. */
  struct tm *tm_ptr; /* tm構造体へのポインタtm_ptr. */
  char time_str[128]; /* 時刻文字列time_str. */
  int content_length = 0; /* Content-Lengthの値を0で初期化. */
  char content_length_str[128]; /* Content-Lengthの値を文字列にしたものcontent_length_str. */
  time_t expires_t; /* 期限時間expires_t. */
  struct tm *expires_tm_ptr; /* 期限時間構造体へのポインタexpires_tm_ptr. */
  char expires_time_str[128]; /* 期限時間文字列expires_time_str. */
  char basic_authorization_header_str[] = "Authorization: Basic ";
  char *s = NULL;
  char *e = NULL;
  char basic_str[256] = {0};
  BIO *base64 = NULL; /* Base64フィルタBIOへのポインタbase64をNULLに初期化. */
  BIO *mem = NULL; /* メモリ用データシンクBIOへのポインタmemをNULLに初期化. */
  BUF_MEM *bptr = NULL; /* バッファメモリポインタbptrをNULLに初期化. */
  char buf[1024] = {0}; /* 文字列バッファbuf(長さ1024)を{0}で初期化. */

  /* Base64変換 */
  base64 = BIO_new(BIO_f_base64());
  mem = BIO_new(BIO_s_mem());
  base64 = BIO_push(base64, mem);
  BIO_write(base64, "testuser:test123", strlen("testuser:test123"));
  BIO_flush(base64);
  BIO_get_mem_ptr(base64, &bptr);
  memcpy(buf, bptr->data, bptr->length - 1);
  buf[bptr->length - 1] = '\0';
  printf("buf = [%s]\n", buf);
  BIO_free_all(base64);

  /* 終わるまでループ. */
  while (1){ /* 無限ループ. */

    /* アクセプト処理 */
    client_addr_len = sizeof(client_addr); /* サイズ取得 */
    acc = accept(soc, (struct sockaddr *)&client_addr, &client_addr_len); /* acceptでaccやclient_addrを取得. */
    if (acc < 0){ /* 0未満は終了. */
      perror("accept"); /* "accept"エラー. */
      ret = -1; /* "accept"エラーはretが-1. */
      break; /* ループから抜ける. */
    }

    /* クライアント情報の表示 */
    client_ip_addr_str = inet_ntoa(client_addr.sin_addr); /* inet_ntoaでクライアントのclient_addr.sin_addrをIPアドレス文字列に変換. */
    client_port = ntohs(client_addr.sin_port); /* ntohsでクライアントのclient_addr.sin_portを符号なし10進整数のポート番号に変換. */
    printf("accept!(IPAddress = %s, Port = %hu)\n", client_ip_addr_str, client_port); /* IPアドレスとポートを表示. */

    /* 読み込み */
    memset(recv_buf, 0, sizeof(char) * 4096); /* recv_bufをクリア. */
    recv(acc, recv_buf, sizeof(recv_buf), 0); /* recvでaccから読み込み, recv_bufに格納. */
    printf("----- recv begin -----\n"); /* recv beginフォームを出力. */
    printf("%s\n", recv_buf); /* recv_bufを出力. */
    printf("----- recv end -----\n"); /* recv endフォームを出力. */

    /* 認証資格情報の取得. */
    s = strstr(recv_buf, basic_authorization_header_str); /* strstrでAuthorizationヘッダを探す. */
    if (s){ /* 有り */
      s = s + strlen(basic_authorization_header_str);
      e = strstr(s, "\r");
      if (e){ /* 有り */
        strncpy(basic_str, s, e - s);
        basic_str[e - s] = '\0';
        printf("basic_str = [%s]\n", basic_str); /* basic_strを出力. */
      }
    }
 
    /* 現在時刻文字列の作成. */
    t = time(NULL); /* timeでtを取得. */
    tm_ptr = gmtime(&t); /* gmtimeでtm_ptrを取得. */
    strftime(time_str, sizeof(time_str), "%Y/%m/%d %H:%M:%S %Z", tm_ptr); /* strftimeでtime_str作成. */

    /* 期限時刻文字列の作成. */
    expires_t = t + 5 * 60; /* 5分. */
    expires_tm_ptr = gmtime(&expires_t); /* expires_tm_ptrを取得. */
    strftime(expires_time_str, sizeof(expires_time_str), "%a, %d %b %Y %H:%M:%S %Z", expires_tm_ptr); /* strftimeでexpires_time_str作成. */

    /* 認証視覚情が一致するか判定. */
    if (strcmp(basic_str, buf) == 0){ /* 一致. */

      /* レスポンスボディの作成. */
      strcpy(response_body, "<html>\r\n"); /* response_bodyに"<hmtl>\r\n"をコピー. */
      strcat(response_body, "  <head>\r\n"); /* response_bodyに"  <head>\r\n"を連結. */
      strcat(response_body, "    <title>HTTP 200 OK</title>\r\n"); /* response_bodyに"    <title>HTTP 200 OK</title>\r\n"を連結. */
      strcat(response_body, "  </head>\r\n"); /* response_bodyに"  </head>\r\n"を連結. */
      strcat(response_body, "  <body>\r\n"); /* response_bodyに"  <body>\r\n"を連結. */
      strcat(response_body, "    "); /* response_bodyに"    "を連結. */
      strcat(response_body, "HTTP 200 OK"); /* response_bodyに"HTTP 200 OK"を連結. */
      strcat(response_body, "\r\n"); /* response_bodyに"\r\n"を連結. */
      strcat(response_body, "  </body>\r\n"); /* response_bodyに"  </body>\r\n"を連結. */
      strcat(response_body, "</html>\r\n"); /* response_bodyに"</html>\r\n"を連結. */

      /* レスポンスヘッダの作成. */
      strcpy(response_header, "HTTP/1.1 200 OK\r\n"); /* response_headerに"HTTP/1.1 200 OK\r\n"をコピー. */

    }
    else{ /* 不一致. */

      /* レスポンスボディの作成. */
      strcpy(response_body, "<html>\r\n"); /* response_bodyに"<hmtl>\r\n"をコピー. */
      strcat(response_body, "  <head>\r\n"); /* response_bodyに"  <head>\r\n"を連結. */
      strcat(response_body, "    <title>HTTP 401 Unauthorized</title>\r\n"); /* response_bodyに"    <title>HTTP 401 Unauthorized</title>\r\n"を連結. */
      strcat(response_body, "  </head>\r\n"); /* response_bodyに"  </head>\r\n"を連結. */
      strcat(response_body, "  <body>\r\n"); /* response_bodyに"  <body>\r\n"を連結. */
      strcat(response_body, "    "); /* response_bodyに"    "を連結. */
      strcat(response_body, "HTTP 401 Unauthorized"); /* response_bodyに"HTTP 401 Unauthorized"を連結. */
      strcat(response_body, "\r\n"); /* response_bodyに"\r\n"を連結. */
      strcat(response_body, "  </body>\r\n"); /* response_bodyに"  </body>\r\n"を連結. */
      strcat(response_body, "</html>\r\n"); /* response_bodyに"</html>\r\n"を連結. */

      /* レスポンスヘッダの作成. */
      strcpy(response_header, "HTTP/1.1 401 Unauthorized\r\n"); /* response_headerに"HTTP/1.1 401 Unauthorized\r\n"をコピー. */
      strcat(response_header, "WWW-Authenticate: Basic\r\n"); /* response_headerに"WWW-Authenticate: Basic\r\n"を連結. */

    }

    /* レスポンスの送信. */
    strcpy(send_buf, response_header); /* send_bufにresponse_headerをコピー. */
    strcat(send_buf, "\r\n"); /* send_bufに"\r\n"を連結. */
    strcat(send_buf, response_body); /* send_bufにresponse_bodyを連結. */
    send(acc, send_buf, strlen(send_buf), 0); /* send_bufを送信. */

    /* アクセプトしたクライアントソケットファイルディスクリプタを閉じる. */
    close(acc); /* closeでaccを閉じる. */

  }

  /* retを返す. */
  return ret; /* retを返して終了. */

}
