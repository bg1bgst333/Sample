/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <openssl/md5.h> /* MD5 */

/* main関数の定義 */
int main(void){

  /* 変数と配列の宣言や初期化. */
  MD5_CTX md5_ctx; /* MD5コンテキストmd5_ctx */
  int result; /* 関数の戻り値を格納するint型変数result. */
  char str[] = "ABCDE"; /* char型配列strを"ABCDE"で初期化. */

  /* MD5コンテキストの初期化. */
  result = MD5_Init(&md5_ctx); /* MD5_Initにmd5_ctxのアドレスを渡して初期化. */
  if (result == 1){ /* 成功 */
    printf("MD5_Init success!\n"); /* "MD5_Init success!"と出力. */
  }
  else{
    printf("MD5_Init error!\n"); /* "MD5_Init error!"と出力. */
    return -1; /* -1を返して終了. */
  }

  /* ソースデータの追加. */
  result = MD5_Update(&md5_ctx, str, strlen(str)); /* MD5_Updateでソースデータとしてstrを追加. */
  if (result == 1){ /* 成功 */
    printf("MD5_Update success!\n"); /* "MD5_Update success!"と出力. */
  }
  else{
    printf("MD5_Update error!\n"); /* MD5_Update error!"と出力. */
    return -2; /* -2を返して終了. */
  }


  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
