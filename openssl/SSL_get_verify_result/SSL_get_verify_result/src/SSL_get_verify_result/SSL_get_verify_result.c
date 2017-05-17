/* ヘッダファイルのインクルード */
#include <openssl/bio.h> /* BIO */
#include <openssl/ssl.h> /* SSL */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  SSL_CTX *ctx = NULL; /* SSL_CTX構造体へのポインタctxをNULLに初期化. */
  BIO *bio = NULL; /* BIO構造体へのポインタbioをNULLに初期化. */
  SSL *ssl = NULL; /* SSL接続情報を持つSSL構造体へのポインタsslをNULLに初期化. */
  long ssl_mode = 0; /* SSLモードlong型ssl_modeを0に初期化. */
  long ssl_result = 0; /* SSL証明書の検証結果long型ssl_resultを0に初期化. */
  char request_str[1024] = {0}; /* char型配列request_str(要素数1024)を0で初期化. */
  int request_len = 0; /* request_strの長さrequest_lenを0で初期化. */
  char response_buf[1024] = {0}; /* char型配列response_buf(要素数1024)を0で初期化. */
  int response_len = 0; /* BIO_readで読み込んだ長さを格納するresponse_lenを0で初期化. */

  /* SSLライブラリの初期化. */
  SSL_library_init(); /* SSL_library_initでSSLライブラリの初期化をする. */

  /* SSLコンテキストの作成. */
  ctx = SSL_CTX_new(SSLv23_client_method()); /* SSL_CTX_newでSSLコンテキストを作成し, SSL_CTX型ポインタとしてctxに格納. +/

  /* ctxの指すアドレスを出力. */
  printf("ctx = %08x\n", ctx); /* printfでctxの指すアドレスを出力. */

  /* 信頼できる証明書ストアのロード. */
  if (!SSL_CTX_load_verify_locations(ctx, "/etc/pki/tls/cert.pem", NULL)){ /* SSL_CTX_load_verify_locationsにctxとpemのパスを渡し, 失敗ならエラーメッセージ. */

    /* エラーメッセージ */
    printf("SSL_CTX_load_verify_locations error!\n"); /* "SSL_CTX_load_verify_locations error!"と出力. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    return -1; /* -1を返して終了. */

  }

  /* ロード成功 */
  printf("SSL_CTX_load_verify_locations success!\n"); /* "SSL_CTX_load_verify_locations success!"と出力. */

  /* BIOのSSLコネクション作成. */
  bio = BIO_new_ssl_connect(ctx); /* BIO_new_ssl_connectにctxを渡してSSLコネクション作成. */
  if (bio == NULL){ /* bioがNULLなら. */

    /* エラーメッセージ */
    printf("BIO_new_ssl_connect error!\n"); /* "BIO_new_ssl_connect error!\n"と出力. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    return -2; /* -2を返して終了. */

  }

  /* 作成成功 */
  printf("BIO_new_ssl_connect success! bio = %08x\n", bio); /* bioの値を出力. */

  /* SSL接続情報の取得. */
  BIO_get_ssl(bio, &ssl); /* BIO_get_sslでbioからsslを取得. */
  printf("ssl = %08x\n", ssl); /* sslの値を出力. */ 

  /* SSLモードの取得. */
  ssl_mode = SSL_get_mode(ssl); /* SSL_get_modeでsslからssl_modeを取得. */
  printf("ssl_mode = %08x\n", ssl_mode); /* ssl_modeを出力. */

  /* SSLモードの設定. */
  SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY); /* SSL_set_modeでsslにSSL_MODE_AUTO_RETRYをセット. */
  ssl_mode = SSL_get_mode(ssl); /* SSL_get_modeでsslからssl_modeを取得. */
  printf("ssl_mode = %08x\n", ssl_mode); /* ssl_modeを出力. */
  if (ssl_mode & SSL_MODE_AUTO_RETRY){ /* ssl_modeにSSL_MODE_AUTO_RETRYが含まれていたら. */
    printf("SSL_MODE_AUTO_RETRY\n"); /* "SSL_MODE_AUTO_RETRY"を出力. */
  }

  /* BIOにホスト情報をセット. */
  /*BIO_set_conn_hostname(bio, "bgstation0.com:443");*/ /* BIO_set_conn_hostnameでホスト名"bgstation0.com"とポート443をセット. */
  BIO_set_conn_hostname(bio, "www.google.co.jp:443"); /* BIO_set_conn_hostnameでホスト名"www.google.co.jp"とポート443をセット. */

  /* 接続 */
  if (BIO_do_connect(bio) <= 0){ /* BIO_do_connectで接続. */

    /* エラーメッセージ */
    printf("BIO_do_connect error!\n"); /* "BIO_do_connect error!"と出力. */
    BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    return -3; /* -3を返して終了. */

  }

  /* SSL証明書の検証. */
  ssl_result = SSL_get_verify_result(ssl); /* SSL_get_verify_resultでSSL証明書の検証結果を取得する. */
  printf("SSL_get_verify_result! ssl_result = %ld\n", ssl_result); /* ssl_resultの値を出力. */
  if (ssl_result != X509_V_OK){ /* X509_V_OKでなければ. */

    /* 証明書エラー */
    printf("SSL_get_verify_result error!\n"); /* "SSL_get_verify_result error!"と出力. */
    BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */
    SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */
    return -4; /* -4を返して終了. */

  }

  /* 接続できている. */
  printf("BIO_do_connect success! bio = %08x\n", bio); /* bioの値を出力. */

  /* GETリクエスト文字列の作成. */
  strcat(request_str, "GET / HTTP/1.1\r\n"); /* strcatでrequest_strに"GET /index.html HTTP/1.1\r\n"を>連結. */
  strcat(request_str, "Host: www.google.co.jp\r\n"); /* strcatでrequest_strに"Host: www.google.co.jp\r\n"を連結. */
  strcat(request_str, "Connection: Close\r\n\r\n"); /* strcatでrequest_strに"Connection: Close\r\n\r\n"を連結. */

  /* リクエストの長さを計算. */
  request_len = strlen(request_str); /* strlenでrequest_strの長さを取得し, request_lenに格納. */

  /* リクエストの書き込み. */
  BIO_write(bio, request_str, request_len); /* BIO_writeでrequest_strを書き込む. */

  /* レスポンスの読み込み. */
  while((response_len = BIO_read(bio, response_buf, 1024 - 1)) > 0){ /* BIO_readで読み込んだレスポンスをresponse_bufに格納.(1バイト以上なら続ける.) */

    /* response_bufの内容を出力. */
    printf("%s", response_buf); /* printfでresponse_bufを出力. */
    memset(response_buf, 0, sizeof(char) * 1024); /* memsetでresponse_bufをクリア. */

  }

  /* BIOのクローズと解放. */
  BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */

  /* SSLコンテキストの解放. */
  SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
