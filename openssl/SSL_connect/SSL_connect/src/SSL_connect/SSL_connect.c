/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <sys/types.h> /* 派生型 */
#include <sys/socket.h> /* ソケット */
#include <netinet/in.h> /* AF_INET, AF_INET6アドレスファミリー */
#include <netdb.h> /* ホスト名変換 */
#include <openssl/bio.h> /* BIO */
#include <openssl/ssl.h> /* SSL */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  struct sockaddr_in target_addr; /* 接続先サーバのIPアドレスやポート番号などの情報target_addr. */
  int ret; /* SSL_connectの戻り値ret. */
  int soc = -1; /* ソケットファイルディスクリプタsocを-1に初期化. */
  struct hostent *host = NULL; /* ホスト情報を格納するhostent構造体へのポインタhostをNULLに初期化. */
  SSL_CTX *ctx = NULL; /* SSL_CTX構造体へのポインタctxをNULLに初期化. */
  SSL *ssl = NULL; /* SSL接続情報を持つSSL構造体へのポインタsslをNULLに初期化. */

  /* ソケットの作成 */
  soc = socket(AF_INET, SOCK_STREAM, 0); /* socketでソケットを作成し, ソケットファイルディスクリプタをsocに格納. */
  if (soc == -1){ /* socが-1の時はエラー. */

    /* エラー処理 */
    printf("socket error!\n"); /* "socket error!"と出力. */
    return -1; /* -1を返す. */

  }

  /* ホスト情報の取得. */
  host = gethostbyname("www.google.co.jp"); /* gethostbynameで"www.google.co.jp"のホスト情報を取得. */
  if (host == NULL){ /* hostがNULLなら. */

    /* エラー */
    printf("gethostbyname error!\n"); /* エラーメッセージ出力. */
    close(soc); /* closeでsocを閉じる. */
    return -2; /* -2を返す. */

  }

  /* 接続先サーバ情報target_addrの設定. */
  target_addr.sin_family = AF_INET; /* IPv4インターネットのアドレスファミリーAF_INET */
  target_addr.sin_port = htons(443); /* ポート番号443 */
  target_addr.sin_addr.s_addr = *(in_addr_t *)host->h_addr_list[0]; /* hostのIPアドレス情報をセット. */

  /* 接続 */
  if (connect(soc, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1){ /* connectで接続先サーバに接続.(-1が返ったらエラー.) */

    /* エラー */
    printf("connect error!\n"); /* "connect error!"と出力. */
    close(soc); /* closeでsocを閉じる. */
    return -3; /* -3を返す. */

  }

  /* 成功したら"connect success." */
  printf("connect success.\n"); /* printfで"connect success."と出力. */

  /* SSLライブラリの初期化. */
  SSL_library_init(); /* SSL_library_initでSSLライブラリの初期化をする. */
  SSL_load_error_strings(); /* SSL_load_error_stringsでエラー文字列をロード. */

  /* SSLコンテキストの作成. */
  ctx = SSL_CTX_new(SSLv23_client_method()); /* SSL_CTX_newでSSLコンテキストを作成し, SSL_CTX型ポインタとしてctxに格納. */

  /* ctxの指すアドレスを出力. */
  printf("ctx = %08x\n", ctx); /* printfでctxの指すアドレスを出力. */

  /* SSL接続情報の作成. */
  ssl = SSL_new(ctx); /* SSL_newでctxからSSL接続情報を作成し, ポインタをsslに格納. */

  /* sslの指すアドレスを出力. */
  printf("ssl = %08x\n", ssl); /* printfでsslの指すアドレスを出力. */

  /* SSL接続情報にソケットファイルディスクリプタをセット. */
  if (SSL_set_fd(ssl, soc) == 0){ /* SSL_set_fdでsslにsocをセット.(戻り値が0なら失敗, 1なら成功.) */

    /* エラー処理 */
    printf("SSL_set_fd error!\n"); /* "SSL_set_fd error!"と出力. */
    ERR_print_errors_fp(stderr); /* ERR_print_errors_fpにstderrを渡して標準エラー出力にエラーメッセージを出力. */
    SSL_free(ssl); /* SSL_freeでsslを解放. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    close(soc); /* closeでsocを閉じる. */
    return -4; /* -4を返す. */

  }

  /* 成功 */
  printf("SSL_set_fd success!\n"); /* "SSL_set_fd success!"と出力. */

  /* SSL接続 */
  ret = SSL_connect(ssl); /* SSL_connectにsslを渡してSSLハンドシェイクを行う. */
  if (ret == 1){ /* 成功 */
    printf("SSL_connect success!\n"); /* "SSL_connect success!"と出力. */
  }
  else{ /* エラー. */

    /* エラー処理 */
    printf("SSL_connect error!\n"); /* "SSL_connect error!"と出力. */
    SSL_free(ssl); /* SSL_freeでsslを解放. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    close(soc); /* closeでsocを閉じる. */
    return -5; /* -5を返す. */

  }

  /* SSL接続情報の破棄. */
  SSL_free(ssl); /* SSL_freeでsslを解放. */
  
  /* SSLコンテキストの解放. */
  SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */

  /* ソケットファイルディスクリプタを閉じる. */
  close(soc); /* closeでsocを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
