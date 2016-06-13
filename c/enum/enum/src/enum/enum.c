/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* 列挙型SEXの定義. */
enum SEX{
  NONE, /* 未設定(0) */
  MALE, /* 男性(1) */
  FEMALE /* 女性(2) */
};

/* 列挙型TEAMNOの定義. */
enum TEAMNO{
  TEAMRED = 10, /* TEAMREDのNoを10とする. */
  TEAMORANGE, /* TEAMORANGEのNoは11となる. */
  TEAMBLUE = 20, /* TEAMBLUEのNoを20とする. */
};

/* 構造体userの定義. */
typedef struct{
  char name[32]; /* 名前 */
  enum SEX sex; /* 性別 */
  enum TEAMNO team_no; /* チームNo */
} user;

/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  user u[3]; /* user型配列u(要素数3) */
  int i; /* ループ用変数i */

  /* u[0]に値をセット. */
  strcpy(u[0].name, "Taro"); /* u[0].nameに"Taro"をセット. */
  u[0].sex = NONE; /* u[0].sexはNONE(未設定)にセット. */
  u[0].team_no = TEAMRED; /* u[0].team_noはTEAMREDにセット. */

  /* u[1]に値をセット. */
  strcpy(u[1].name, "Hanako"); /* u[1].nameに"Hanako"をセット. */
  u[1].sex = FEMALE; /* u[1].sexはFEMALE(女性)にセット. */
  u[1].team_no = TEAMORANGE; /* u[1].team_noはTEAMORANGEにセット. */

  /* u[2]に値をセット. */
  strcpy(u[2].name, "Jiro"); /* u[2].nameに"Jiro"をセット. */
  u[2].sex = MALE; /* u[2].sexはMALE(男性)にセット. */
  u[2].team_no = TEAMBLUE; /* u[2].team_noはTEAMBLUEにセット. */

  /* u[0]~u[2]の値を出力. */
  for (i = 0; i < 3; i++){ /* 3回繰り返す. */
    printf("u[%d].name = %s\n", i, u[i].name); /* printfでu[i].nameを出力. */
    printf("u[%d].sex = %d\n", i, (int)u[i].sex); /* printfでu[i].sexを出力. */
    printf("u[%d].team_no = %d\n", i, (int)u[i].team_no); /* printfでu[i].team_noを出力. */
  }

  /* プログラムの終了 */
  return 0;

}
