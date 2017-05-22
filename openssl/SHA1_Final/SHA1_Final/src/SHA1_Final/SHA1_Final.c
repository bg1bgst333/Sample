/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <openssl/sha.h> /* SHA */

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  SHA_CTX sha_ctx; /* SHA1コンテキストsha_ctx */
  int result; /* 関数の戻り値を格納するint型変数result. */
  unsigned char sha1[SHA_DIGEST_LENGTH]; /* unsigned char型SHA1配列sha1. */
  int i; /* ループ用変数i. */
  char str[] = "ABCDE"; /* char型配列strを"ABCDE"で初期化. */

  /* SHA1コンテキストの初期化. */
  result = SHA1_Init(&sha_ctx); /* SHA1_Initにsha_ctxのアドレスを渡して初期化. */
  if (result == 1){ /* 成功 */
    printf("SHA1_Init success!\n"); /* "SHA1_Init success!"と出力. */
  }
  else{
    printf("SHA1_Init error!\n"); /* SHA1_Init error!"と出力. */
    return -1; /* -1を返して終了. */
  }

  /* ソースデータの追加. */
  result = SHA1_Update(&sha_ctx, str, strlen(str)); /* SHA1_Updateでソースデータとしてstrを追加. */
  if (result == 1){ /* 成功 */
    printf("SHA1_Update success!\n"); /* "SHA1_Update success!"と出力. */
  }
  else{
    printf("SHA1_Update error!\n"); /* "SHA1_Update error!"と出力. */
    return -2; /* -2を返して終了. */
  }

  /* デストバッファにsha1ハッシュを格納. */
  result = SHA1_Final(sha1, &sha_ctx); /* SHA1_Finalでsha1にハッシュ値を書き出す. */
  if (result == 1){ /* 成功 */
    printf("SHA1_Final success!\n"); /* "SHA1_Final success!"と出力. */
  }
  else{
    printf("SHA1_Final error!\n"); /* "SHA1_Final error!"と出力. */
    return -3; /* -3を返して終了. */
  }

  /* SHA1の出力. */
  printf("sha1 = "); /* sha1 = "と出力. */
  for (i = 0; i < SHA_DIGEST_LENGTH; i++){ /* SHA_DIGEST_LENGTHの分だけ繰り返す. */
    printf("%02x", sha1[i]); /* sha1の各要素を16神数で出力. */
  }
  printf("\n"); /* 改行 */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
