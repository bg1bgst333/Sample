/* ヘッダファイルのインクルード */
#include <openssl/bio.h> /* BIO */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  BIO *bio = NULL; /* BIO構造体へのポインタbioをNULLに初期化. */

  /* BIOのオープンと接続. */
  bio = BIO_new_connect("bgstation0.com:443"); /* BIO_new_connectで"bgstation0.com"をポート443でオープン及び接続し, BIOのポインタをbioに格納. */
  if (bio == NULL){ /* bioがNULLなら.

    /* エラーメッセージ */
    printf("BIO_new_connect error!\n"); /* "BIO_new_connect error!"と出力. */
    return -1; /* -1を返して終了. */

  }

  /* 接続成功 */
  printf("BIO_new_connect success! bio = %08x\n", bio); /* bioの値を出力. */

  /* BIOのクローズと解放. */
  BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}
