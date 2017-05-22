/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <openssl/md5.h> /* MD5 */

/* main関数の定義 */
int main(void){

  /* 変数と配列の宣言や初期化. */
  MD5_CTX md5_ctx; /* MD5コンテキストmd5_ctx */
  int result; /* 関数の戻り値を格納するint型変数result. */
  unsigned char md5[MD5_DIGEST_LENGTH]; /* unsigned char型MD5配列md5. */
  int i; /* ループ用変数i. */
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
    printf("MD5_Update error!\n"); /* "MD5_Update error!"と出力. */
    return -2; /* -2を返して終了. */
  }

  /* デストバッファにMD5ハッシュを格納. */
  result = MD5_Final(md5, &md5_ctx); /* MD5_Finalでmd5にハッシュ値を書き出す. */
  if (result == 1){ /* 成功 */
    printf("MD5_Final success!\n"); /* "MD5_Final success!"と出力. */
  }
  else{
    printf("MD5_Final error!\n"); /* "MD5_Final error!"と出力. */
    return -3; /* -3を返して終了. */
  }

  /* MD5の出力. */
  printf("md5 = "); /* "md5 = "と出力. */
  for (i = 0; i < MD5_DIGEST_LENGTH; i++){ /* MD5_DIGEST_LENGTHの分だけ繰り返す. */
    printf("%02x", md5[i]); /* md5の各要素を16進数で出力. */
  }
  printf("\n"); /* 改行 */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
