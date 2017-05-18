/* ヘッダファイルのインクルード */
#include <openssl/bio.h> /* BIO */
#include <openssl/ssl.h> /* SSL */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  SSL_CTX *ctx = NULL; /* SSL_CTX構造体へのポインタctxをNULLに初期化. */
  SSL *ssl = NULL; /* SSL接続情報を持つSSL構造体へのポインタsslをNULLに初期化. */

  /* SSLライブラリの初期化. */
  SSL_library_init(); /* SSL_library_initでSSLライブラリの初期化をする. */

  /* SSLコンテキストの作成. */
  ctx = SSL_CTX_new(SSLv23_client_method()); /* SSL_CTX_newでSSLコンテキストを作成し, SSL_CTX型ポインタとしてctxに格納. */

  /* ctxの指すアドレスを出力. */
  printf("ctx = %08x\n", ctx); /* printfでctxの指すアドレスを出力. */

  /* SSL接続情報の作成. */
  ssl = SSL_new(ctx); /* SSL_newでctxからSSL接続情報を作成し, ポインタをsslに格納. */

  /* sslの指すアドレスを出力. */
  printf("ssl = %08x\n", ssl); /* printfでsslの指すアドレスを出力. */

  /* SSL接続情報の破棄. */
  SSL_free(ssl); /* SSL_freeでsslを解放. */
  
  /* SSLコンテキストの解放. */
  SSL_CTX_free(ctx); /* SSL_CTX_freeでctxを解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
