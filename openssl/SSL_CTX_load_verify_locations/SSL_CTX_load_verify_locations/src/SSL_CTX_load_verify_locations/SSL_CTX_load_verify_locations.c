/* ヘッダファイルのインクルード */
#include <openssl/bio.h> /* BIO */
#include <openssl/ssl.h> /* SSL */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  SSL_CTX *ctx = NULL; /* SSL_CTX構造体へのポインタctxをNULLに初期化. */

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

  /* SSLコンテキストの解放. */
  SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
