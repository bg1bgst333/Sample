/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <libpq-fe.h> /* libpqフロントエンド */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  PGconn *con; /* PGconnポインタcon */
  PGresult *res; /* PGresultポインタres */
  ExecStatusType type; /* ExecStatusType型type */
  int field_count; /* フィールドの数field_count */

  /* DB接続 */
  con = PQconnectdb("host=localhost dbname=testuser1db user=testuser1 password=test1234test"); /* PQconnectdbでtestuser1dbに接続. */
  if (PQstatus(con) == CONNECTION_OK){ /* 接続成功 */
    printf("CONNECTION_OK\n"); /* "CONNECTION_OK"を出力. */

    /* SQL実行 */
    res = PQexec(con, "SELECT * FROM user_profile;"); /* PQexecでSQL文"SELECT * FROM user_profile;"を実行. */
    type = PQresultStatus(res); /* PQresultStatusで結果を取得. */
    if (type == PGRES_TUPLES_OK){ /* 成功 */
      printf("PGRES_TUPLES_OK\n"); /* "PGRES_TUPLES_OK"と出力. */

      /* フィールドの数を取得. */
      field_count = PQnfields(res); /* PQnfieldsでフィールドの数を取得し, field_countに格納. */
      printf("field_count = %d\n", field_count); /* field_countを出力. */

      PQclear(res); /* resの解放 */
      PQfinish(con); /* PQfinishでconの接続を終了. */
      return 0; /* 0を返して正常終了. */
    }
    else if (type == PGRES_EMPTY_QUERY){ /* クエリが空. */
      printf("PGRES_EMPTY_QUERY\n"); /* "PGRES_EMPTY_QUERY"と出力. */
      PQclear(res); /* resの解放 */
      PQfinish(con); /* PQfinishでconの接続を終了. */
      return -1; /* -1を返して異常終了. */
    }
    else if (type == PGRES_FATAL_ERROR){ /* SQL文がおかしい場合など. */
      printf("PGRES_FATAL_ERROR\n"); /* "PGRES_FATAL_ERROR"と出力. */
      PQclear(res); /* resの解放 */
      PQfinish(con); /* PQfinishでconの接続を終了. */
      return -1; /* -1を返して異常終了. */
    }
    else{ /* その他の失敗 */
      printf("NG\n"); /* "NG"と出力. */
      PQclear(res); /* resの解放 */
      PQfinish(con); /* PQfinishでconの接続を終了. */
      return -1; /* -1を返して異常終了. */
    }

  }
  else if (PQstatus(con) == CONNECTION_BAD){ /* 接続失敗 */
    printf("CONNECTION_BAD\n"); /* "CONNECTION_BAD"を出力. */
    return -1; /* -1を返して異常終了. */
  }

}
