/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <openssl/sha.h> /* SHA */
#include <openssl/evp.h> /* EVP */
#include <openssl/hmac.h> /* HMAC */

/* main関数の定義 */
int main(void){

  /* 変数の宣言と初期化. */
  char key[] = "ABC&XYZ"; /* char型配列keyを"ABC&XYZ"と初期化. */
  int key_len; /* int型key_len. */
  char data[] = "ABCDE"; /* char型配列dataを"ABCDE"と初期化. */
  int data_len; /* int型data_len. */
  char hmac_sha1[SHA_DIGEST_LENGTH + 1]; /* char型配列hmac_sha1. */
  int hmac_sha1_len; /* int型hmac_sha1_len. */
  BIO *mem = NULL; /* メモリデータシンクBIO */
  BIO *base64 = NULL; /* Base64フィルタBIO */
  char base64_str[1024] = {0}; /* char型配列base64_strを0で初期化. */

  /* keyの長さを計算. */
  key_len = strlen(key); /* strlenでkeyの長さを計算し, key_lenに格納. */

  /* dataの長さを計算. */
  data_len = strlen(data); /* strlenでdataの長さを計算し, data_lenに格納. */

  /* HMAC-SHA1の計算. */
  HMAC(EVP_sha1(), key, key_len, data, data_len, hmac_sha1, &hmac_sha1_len); /* HMAC()でHMAC-SHA1を計算. */

  /* hmac_sha1の出力. */
  printf("hmac_sha1 = %s\n", hmac_sha1); /* printfでhmac_sha1を出力. */

  /* memの作成. */
  mem = BIO_new(BIO_s_mem()); /* BIO_new()にBIO_s_mem()を渡してmemを作成. */

  /* base64の作成. */
  base64 = BIO_new(BIO_f_base64()); /* BIO_new()にBIO_f_base64()を渡してbase64を作成. */

  /* base64とmemを連結. */
  BIO_push(base64, mem); /* BIO_pushでbase64とmemを連結. */

  /* base64に書き込み. */
  BIO_write(base64, hmac_sha1, hmac_sha1_len); /* base64にhmac_sha1を書き込み. */

  /* フラッシュ */
  BIO_flush(base64); /* BIO_flushでフラッシュ. */

  /* memを読み込み. */
  BIO_read(mem, base64_str, 1024); /* BIO_readでmemを読み込み, base64_strに格納. */

  /* base64_strの出力. */
  printf("base64_str = %s\n", base64_str); /* printfでbase64_strの出力. */

  /* 解放 */
  BIO_free_all(base64); /* base64と連結しているmemも解放される. */
  
  /* プログラムの終了. */
  return 0; /* 0を返す. */

}
