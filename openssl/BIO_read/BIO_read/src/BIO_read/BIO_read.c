/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <openssl/bio.h> /* BIO */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  BIO *bio = NULL; /* BIO構造体へのポインタbioをNULLに初期化. */
  char request_str[1024] = {0}; /* char型配列request_str(要素数1024)を0で初期化. */
  int request_len = 0; /* request_strの長さrequest_lenを0で初期化. */
  char response_buf[1024] = {0}; /* char型配列response_buf(要素数1024)を0で初期化. */
  int response_len = 0; /* BIO_readで読み込んだ長さを格納するresponse_lenを0で初期化. */

  /* BIOのコネクション作成. */
  bio = BIO_new_connect("bgstation0.com:80"); /* BIO_new_connectでサーバ名"bgstation0.com"のポート80でコネクションを作成し, BIOのポインタをbioに格納. */
  if (bio == NULL){ /* bioがNULLなら. */

    /* エラーメッセージ */
    printf("BIO_new_connect error!\n"); /* "BIO_new_connect error!"と出力. */
    return -1; /* -1を返して終了. */

  }

  /* 接続 */
  if (BIO_do_connect(bio) <= 0){ /* BIO_do_connectで接続. */

    /* エラーメッセージ */
    printf("BIO_do_connect error!\n"); /* "BIO_do_connect error!"と出力. */
    BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */
    return -2; /* -2を返して終了. */

  }

  /* GETリクエスト文字列の作成. */
  strcat(request_str, "GET /index.html HTTP/1.1\r\n"); /* strcatでrequest_strに"GET /index.html HTTP/1.1\r\n"を連結. */
  strcat(request_str, "Host: bgstation0.com\r\n"); /* strcatでrequest_strに"Host: bgstation0.com\r\n"を連結. */
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

  /* BIOのクローズと開放. */
  BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
