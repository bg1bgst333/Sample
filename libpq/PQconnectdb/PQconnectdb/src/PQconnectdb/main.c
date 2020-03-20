/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <libpq-fe.h> /* libpqフロントエンド */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  PGconn *con; /* PGconnポインタcon */

  /* DB接続 */
  con = PQconnectdb("host=localhost dbname=testuser1db user=testuser1 password=test1234test"); /* PQconnectdbでtestuser1dbに接続. */
  if (PQstatus(con) == CONNECTION_BAD){ /* 接続失敗 */
    printf("CONNECTION_BAD\n"); /* "CONNECTION_BAD"を出力. */
    printf("%s\n", PQerrorMessage(con));
    return -1; /* -1を返して異常終了. */
  }
  printf("OK\n"); /* "OK"と出力. */
  PQfinish(con); /* PQfinishでconの接続を終了. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}
