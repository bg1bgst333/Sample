/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 構造体struct_flagsの定義 */
struct struct_flags{
  unsigned char is_adult: 1; /* 大人かどうか(1bit). */
  unsigned char is_male: 1; /* 男かどうか(1bit). */
  unsigned char is_sportsman: 1; /* スポーツマンかどうか(1bit). */
  unsigned char is_artist: 1; /* アーティストかどうか(1bit). */
  unsigned char no: 4; /* 番号(4bit). */
};

/* main関数の定義 */
int main(void){

  /* 構造体変数の定義 */
  struct struct_flags flg; /* struct_flags構造体変数flg. */

  /* struct_flagsのサイズ */
  printf("sizeof(struct struct_flags) = %d\n", sizeof(struct struct_flags)); /* printfでsizeof(struct struct_flags)を出力. */

  /* 値のセット */
  flg.is_adult = 1; /* flg.is_adultに1をセット. */
  flg.is_male = 1; /* flg.is_maleに1をセット. */
  flg.is_sportsman = 0; /* flg.is_sportsmanに0をセット. */
  flg.is_artist = 1; /* flg.is_artistに1をセット. */
  flg.no = 10; /* flg.noに10をセット. */


  /* 値の出力 */
  printf("flg.is_adult = %hu\n", flg.is_adult); /* flg.is_adultを出力. */
  printf("flg.is_male = %hu\n", flg.is_male); /* flg.is_maleを出力. */
  printf("flg.is_sportsman = %hu\n", flg.is_sportsman); /* flg.is_sportsmanを出力. */
  printf("flg.is_artist = %hu\n", flg.is_artist); /* flg.is_artistを出力. */
  printf("flg.no = %hu\n", flg.no); /* flg.noを出力. */

  /* プログラムの終了 */
  return 0;

}
