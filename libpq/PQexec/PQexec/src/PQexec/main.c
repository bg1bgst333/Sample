/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <libpq-fe.h> /* libpqフロントエンド */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  PGconn *con; /* PGconnポインタcon */
  PGresult *res; /* PGresultポインタres */

  /* DB接続 */
  con = PQconnectdb("host=localhost dbname=testuser1db user=testuser1 password=test1234test"); /* PQconnectdbでtestuser1dbに接続. */
  if (PQstatus(con) == CONNECTION_OK){ /* 接続成功 */
    printf("CONNECTION_OK\n"); /* "CONNECTION_OK"を出力. */

    /* SQL実行 */
    res = PQexec(con, "SELECT * FROM user_profile;"); /* PQexecでSQL文"SELECT * FROM user_profile;"を実行. */
    if (PQresultStatus(res) != PGRES_TUPLES_OK){ /* 失敗 */
      printf("NG\n"); /* "NG"と出力. */
      PQclear(res); /* resの解放 */
      PQfinish(con); /* PQfinishでconの接続を終了. */
      return -1; /* -1を返して異常終了. */
    }
    printf("OK\n"); /* "OK"と出力. */

    /* 終了処理 */
    PQclear(res); /* resの解放 */
    PQfinish(con); /* PQfinishでconの接続を終了. */
    return 0; /* 0を返して正常終了. */

  }
  else if (PQstatus(con) == CONNECTION_BAD){ /* 接続失敗 */
    printf("CONNECTION_BAD\n"); /* "CONNECTION_BAD"を出力. */
    return -1; /* -1を返して異常終了. */
  }

}
