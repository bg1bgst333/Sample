/* ヘッダファイルのインクルード */
#include <openssl/bio.h> /* BIO */
#include <openssl/err.h> /* エラー */

/* main関数の定義 */
int main(void){

  /* 変数の初期化 */
  BIO *bio = NULL; /* BIO構造体へのポインタbioをNULLに初期化. */

  /* BIOの接続作成. */
  bio = BIO_new_connect("bgstation0.com:80"); /* BIO_new_connectでサーバ名"bgstation0.com"のポート80で接続を作成し, BIOのポインタをbioに格納. */
  if (bio == NULL){ /* bioがNULLなら.

    /* エラーメッセージ */
    printf("BIO_new_connect error!\n"); /* "BIO_new_connect error!"と出力. */
    return -1; /* -1を返して終了. */

  }

  /* 接続の確認 */
  if (BIO_do_connect(bio) <= 0){ /* BIO_do_connectでbioの接続ができているか確認. */

    /* エラーメッセージ */
    printf("BIO_do_connect error!\n"); /* "BIO_do_connect error!"と出力. */
    BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */
    return -2; /* -2を返して終了. */

  }

  /* 接続できている. */
  printf("BIO_do_connect success! bio = %08x\n", bio); /* bioの値を出力. */

  /* BIOのクローズと解放. */
  BIO_free_all(bio); /* BIO_free_allでbioをクローズ及び解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して終了. */

}  
