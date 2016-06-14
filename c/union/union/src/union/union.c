/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* 共用体union_userの定義. */
union union_user{
  /* 構造体struct_user_nの定義. */
  struct struct_user_n{
    char name[8]; /* 名前 */
  } user_n;
  /* 構造体struct_user_naの定義. */
  struct struct_user_na{
    char name[8]; /* 名前 */
    int age; /* 年齢 */
  } user_na;
  /* 構造体struct_user_nanの定義. */
  struct struct_user_nan{
    char name[8]; /* 名前 */
    int age; /* 年齢 */
    int no; /* 番号 */
  } user_nan;
};

/* main関数の定義 */
int main(void){

  /* 共用体配列の初期化. */
  union union_user u[3] = {0}; /* すべて0で初期化しておく. */

  /* 共用体のサイズ. */
  printf("sizeof(union union_user) = %d\n", sizeof(union union_user)); /* printfでunion union_userのsizeofした値を出力. */

  /* 共用体に値をセット. */
  strcpy(u[0].user_n.name, "Taro"); /* u[0].user_n.nameに"Taro"をセット. */
  strcpy(u[1].user_na.name, "Jiro"); /* u[1].user_na.nameに"Jiro"をセット. */
  u[1].user_na.age = 18; /* u[1].user_na.ageに18をセット. */
  strcpy(u[2].user_nan.name, "Saburo"); /* u[2].user_nan.nameに"Saburo"をセット. */
  u[2].user_nan.age = 16; /* u[2].user_nan.ageに16をセット. */
  u[2].user_nan.no = 3; /* u[2].user_nan.noに3をセット. */

  /* 値の出力. */
  /* u[0]の出力. */
  printf("u[0].user_n.name = %s\n", u[0].user_n.name); /* u[0].user_n.nameを出力. */
  printf("u[0].user_na.name = %s\n", u[0].user_na.name); /* u[0].user_na.nameを出力. */
  printf("u[0].user_na.age = %d\n", u[0].user_na.age); /* u[0].user_na.ageを出力. */
  printf("u[0].user_nan.name = %s\n", u[0].user_nan.name); /* u[0].user_nan.nameを出力. */
  printf("u[0].user_nan.age = %d\n", u[0].user_nan.age); /* u[0].user_nan.ageを出力. */
  printf("u[0].user_nan.no = %d\n", u[0].user_nan.no); /* u[0].user_nan.noを出力. */

  /* u[1]の出力. */
  printf("u[1].user_n.name = %s\n", u[1].user_n.name); /* u[1].user_n.nameを出力. */
  printf("u[1].user_na.name = %s\n", u[1].user_na.name); /* u[1].user_na.nameを出力. */
  printf("u[1].user_na.age = %d\n", u[1].user_na.age); /* u[1].user_na.ageを出力. */
  printf("u[1].user_nan.name = %s\n", u[1].user_nan.name); /* u[1].user_nan.nameを出力. */
  printf("u[1].user_nan.age = %d\n", u[1].user_nan.age); /* u[1].user_nan.ageを出力. */
  printf("u[1].user_nan.no = %d\n", u[1].user_nan.no); /* u[1].user_nan.noを出力. */

  /* u[2]の出力. */
  printf("u[2].user_n.name = %s\n", u[2].user_n.name); /* u[2].user_n.nameを出力. */
  printf("u[2].user_na.name = %s\n", u[2].user_na.name); /* u[2].user_na.nameを出力. */
  printf("u[2].user_na.age = %d\n", u[2].user_na.age); /* u[2].user_na.ageを出力. */
  printf("u[2].user_nan.name = %s\n", u[2].user_nan.name); /* u[2].user_nan.nameを出力. */
  printf("u[2].user_nan.age = %d\n", u[2].user_nan.age); /* u[2].user_nan.ageを出力. */
  printf("u[2].user_nan.no = %d\n", u[2].user_nan.no); /* u[2].user_nan.noを出力. */

  /* プログラムの終了 */
  return 0;

}
