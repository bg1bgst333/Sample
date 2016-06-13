/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* 既存のunsigned charをbyteという新しい型として定義する. */
typedef unsigned char byte;

/* 構造体タグstruct_tag_profileの定義. */
struct struct_tag_profile{
  char name[32]; /* 名前 */
  int age; /* 年齢 */
  char address[128]; /* 住所 */
};

/* typedefでstruct struct_tag_profileをprofileという新しい型として定義する. */
typedef struct struct_tag_profile profile;

/* タグを省略して新しい型detailとして構造体を定義する. */
typedef struct{
  char name[32]; /* 名前 */
  int age; /* 年齢 */
  char address[128]; /* 住所 */
  char phonenumber[12]; /* 電話番号 */
  int sex; /* 性別 */
} detail;
 
/* main関数の定義 */
int main(void){

  /* 変数の宣言 */
  byte b; /* byte型変数b */
  profile prof; /* profile型変数prof */
  detail det; /* detail型変数det */

  /* 値をセット. */
  b = 0xab; /* bに0xabを代入. */
  strcpy(prof.name, "Taro"); /* prof.nameに"Taro"をセット. */
  prof.age = 20; /* prof.ageに20を代入. */
  strcpy(prof.address, "Tokyo"); /* prof.addressに"Tokyo"をセット. */
  strcpy(det.name, "Jiro"); /* det.nameに"Jiro"をセット. */
  det.age = 18; /* det.ageに18を代入. */
  strcpy(det.address, "Osaka"); /* det.addressに"Osaka"をセット. */
  strcpy(det.phonenumber, "00000000"); /* det.phonenumberに"00000000"をセット. */
  det.sex = 1; /* det.sexに1をセット. */

  /* 値の出力 */
  printf("b = 0x%02x\n", b); /* printfでbを出力. */
  printf("prof.name = %s\n", prof.name); /* printfでprof.nameを出力. */
  printf("prof.age = %d\n", prof.age); /* printfでprof.ageを出力. */
  printf("prof.address = %s\n", prof.address); /* printfでprof.addressを出力. */
  printf("det.name = %s\n", det.name); /* printfでdet.nameを出力. */
  printf("det.age = %d\n", det.age); /* printfでdet.ageを出力. */
  printf("det.address = %s\n", det.address); /* printfでdet.addressを出力. */
  printf("det.phonenumber = %s\n", det.phonenumber); /* printfでdet.phonenumberを出力. */
  printf("det.sex = %d\n", det.sex); /* printfでdet.sexを出力. */

  /* プログラムの終了 */
  return 0;

}
