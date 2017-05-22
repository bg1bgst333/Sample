/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <openssl/md5.h> /* MD5 */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  MD5_CTX md5_ctx; /* MD5コンテキストmd5_ctx */
  int result; /* 関数の戻り値を格納するint型変数result. */

  /* MD5コンテキストの初期化. */
  result = MD5_Init(&md5_ctx); /* MD5_Initにmd5_ctxのアドレスを渡して初期化. */
  if (result == 1){ /* 成功 */
    printf("MD5_Init success!\n"); /* "MD5_Init success!"と出力. */
  }
  else{
    printf("MD5_Init error!\n"); /* "MD5_Init error!"と出力. */
    return -1; /* -1を返して終了. */
  }

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
